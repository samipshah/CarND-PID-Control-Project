#include "Model.h"

void Model::collect(double error, double steering_value, double prev_error) {
    model_input a;
    a.error = error;
    a.steering_value = steering_value;
    a.prev_error = prev_error;
    data.push_back(a);
}

