class ELMRegression {
    constructor(nInput, hiddenLayers, nOutput) {
        this.hiddenLayers = hiddenLayers;
        this.nInput = nInput;
        this.nOutput = nOutput;
        this.layers = [];
        this.outputWeights = [];
        this.outputBias = [];

        // Initialize weights and biases for hidden layers
        let prevLayerSize = nInput;
        for (let hiddenSize of hiddenLayers) {
            this.layers.push({
                weights: this.randomMatrix(hiddenSize, prevLayerSize),
                bias: this.randomMatrix(hiddenSize, 1)
            });
            prevLayerSize = hiddenSize;
        }

        // Initialize weights and bias for the output layer
        this.outputWeights = this.randomMatrix(nOutput, prevLayerSize);
        this.outputBias = this.randomMatrix(nOutput, 1);
    }

    randomMatrix(rows, cols) {
        return Array.from({ length: rows }, () => 
            Array.from({ length: cols }, () => Math.random())
        );
    }

    sigmoid(x) {
        return x.map(row => row.map(value => 1 / (1 + Math.exp(-value))));
    }

    matrixMultiply(A, B) {
        const result = Array.from({ length: A.length }, () => Array(B[0].length).fill(0));
        for (let i = 0; i < A.length; i++) {
            for (let j = 0; j < B[0].length; j++) {
                for (let k = 0; k < A[0].length; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }

    addBias(matrix, bias) {
        return matrix.map((row, i) => row.map((value, j) => value + bias[i][0]));
    }

    forward(x) {
        let activation = x;

        // Forward pass through hidden layers
        for (let layer of this.layers) {
            activation = this.matrixMultiply(layer.weights, activation);
            activation = this.addBias(activation, layer.bias);
            activation = this.sigmoid(activation);
        }

        // Output layer
        activation = this.matrixMultiply(this.outputWeights, activation);
        activation = this.addBias(activation, this.outputBias);
        return activation;
    }

    saveModelJSON() {
        const modelParams = {
            layers: this.layers.map((layer, i) => ({
                weights: layer.weights,
                bias: layer.bias
            })),
            outputWeights: this.outputWeights,
            outputBias: this.outputBias
        };
        console.log(JSON.stringify(modelParams, null, 2));
    }

    static loadModelJSON(modelJson) {
        const modelParams = JSON.parse(modelJson);
        const model = new ELMRegression(modelParams.nInput, modelParams.hiddenLayers, modelParams.nOutput);
        model.layers = modelParams.layers;
        model.outputWeights = modelParams.outputWeights;
        model.outputBias = modelParams.outputBias;
        return model;
    }
}

// Load JSON data from a file
async function loadJSON(filePath) {
    const response = await fetch(filePath);
    return response.json();
}

// Perform ELM regression on the data
async function performELMRegression(filePath, sheetsInJson, hiddenLayers, epochs = 1000) {
    const data = await loadJSON(filePath);
    const results = {};

    for (let sheetName of sheetsInJson) {
        console.log(`Processing sheet: ${sheetName}`);
        const sheetData = data[sheetName];

        // Prepare input (X) and output (y) matrices
        const X = sheetData.map(item => Object.values(item).slice(0, -1)); // All but last column as features
        const y = sheetData.map(item => Object.values(item).slice(-1)); // Last column as output

        const elmModel = new ELMRegression(X[0].length, hiddenLayers, y[0].length);
        
        // Simulate training process (you'd implement actual training logic here)
        console.log(`Training model for ${sheetName}...`);
        for (let epoch = 0; epoch < epochs; epoch++) {
            // Simulate a forward pass (you'd actually train here)
            const predictions = elmModel.forward(X);
            // Normally you'd compute loss and update weights here
        }

        elmModel.saveModelJSON(); // Save the model after training
        results[sheetName] = { predictions }; // Store predictions for each sheet
        console.log(`Completed processing for sheet: ${sheetName}`);
    }

    return results;
}

// Usage example
const filePathJson = 'dataset/dataset_v4.json';
const sheetsInJson = ['Sheet1-KM-SAR-Tiny-Reg', 'Sheet2-M-SAK-T-Tiny-Reg', 'CombinedSheet'];
const hiddenLayers = [100, 50, 25, 12, 6, 3];

performELMRegression(filePathJson, sheetsInJson, hiddenLayers, 1000).then(results => {
    console.log("Results:", results);
});
