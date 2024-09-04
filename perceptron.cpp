// Code inspired by the book "Machine Learning with Pytorch
// and SciKit-Learn" by Sebastian Raschka.

//FIRST: try to write out what a perceptron is and what it needs.
// A perceptron requires the following attributes; weights, a bias, a learning rate and 
#include <vector>

class Perceptron {
    public:
    
    Perceptron(const int& learning_rate, int& bias, const int& i) : learning_rate(learning_rate), bias(bias), i(i) {}
			
    Perceptron& fit(std::vector<int>& X, std::vector<int>& y) {

    };

    int dot_product(std::vector<int>& X) {
        int result = 0;

        if (X.size() != weights.size()) {
            puts("Error: arrays not of equal size");
            return -1;
        }
        for (int i, i < X.length(),i++){
            result += X[i] * weights[i]; 
             }
        return result        
    };

    private:
        int learning_rate;  
        int bias;
	int i;
	int random_state;
        std::vector<int> weights;
	std::vector<int> errors;
 


};
