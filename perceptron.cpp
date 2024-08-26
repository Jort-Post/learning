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

    void normal()

    private:
        int learning_rate;  
        int bias;
	int i;
	int random_state;
        std::vector<int> weights;
	std::vector<int> errors;
 


};
