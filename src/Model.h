#ifndef MODEL_H
#define MODEL_H

#include <vector>
class Model {
    struct model_input {
       double error;
       double steering_value;
       double prev_error; 
    };
    std::vector<model_input> data;
public:
    void collect(double error, double steering_value, double prev_error);
    void learn(); // may be linear regression of the form error = linearfunc(steering_value, prev_error)
    // find using above learnt function twiddle will find next steering_value based on earlier iterations cte
    // it will pass it and get the next cte this way we coudl run many steps without relying on UI.
    double nextCte(double steering_value, double prev_error); 
};

#endif