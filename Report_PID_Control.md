# **PID Control** 
---

**PID Control Project**

The goals / steps of this project are the following:
* Complete the PID.cpp to define the initialization function of the PID class, and the functions computing the PID and total errors.
* Run the simulator and tune the hyper parameters to achieve a good result.
* Summarize the results with a written report.

## Rubric Points
### Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/1972/view) individually and describe how I addressed each point in my implementation.  

---
### Compilation

#### 1. Your code should compile.

My project includes the following files:
* main.cpp containing the script to derive the steering angle.
* PID.cpp defining the function to compute the PID error and total error
* PID.h declaring the variables and member functions
* Report_PID_Control.md summarizing the results

The code could be compiled correctly under the `CarND-PID-Control-Project/build` folder running `cmake .. && make`. The pid file will be generated.

Using the Udacity provided simulator and running the `pid` file under build folder, the controller is tested in the track in the simulator.

### Implementation

#### 1. The PID procedure follows what was taught in the lessons.

In the PID.cpp file the member function compute the proportional, integration, derivative error following the instructions of the lesson.

#### 2. Describe the effect each of the P, I, D components had in your implementation.

The effect of the P component is to steer the vehicle back to the road center. However, with only the P component, the vehicle always oscillated around the road center. Larger is the P component, faster the vehicle corrects itself but the overshoot is also larger.Two videos compared the difference with Kp = 0.007 and Kp = 3 under the folder `Videos`. It showed that with smaller Kp the vehicle corrected itself slowly at the beginning, while with larger Kp the vehicle steered back to the road center faster at first but the overshoot later and quickly became unstable.

The effect of the D component is to reduce the overshoot. Under the folder `Videos` two videos compared the difference with Kd=6 and Kd=9.We could see that with smaller Kd, the oscillation is large. While with larger Kd, the oscillation is relatively small and the vehicle steers back to the road center faster.

The effect of the I component is to cancel the CTE caused by systematic bias.By tuning the parameter I found out that with larger Ki the vehicle tends to have more oscillation.Thus 0.04 is chosen to be the final value of the Ki parameter.


#### 3. Desribe how the final hyperparameters were chosen.

First only the proportional parameter is set, after running the simulator I found the vehicle had a unstable behavior.Then the derivative parameter is set. The proper value of the parameter is defined through manual tuning. After the Kp and Kd parameters are defined, the Ki parameter is tuned indepedently to ameliorate the performance.

#### 4. The vehicle must successfully drive a lap around the track.

This point is checked by running the pid file with the simulator.

## PID control algorithm

First the fine-tuned PID parameters are initialized(Line 41 - 42). Then it will be handled to the simulator(Line 44).

Lines 70 - 71 computed the PID error and updated the steering angle according to the content taught in the lesson.

Lines 73 - 77 set the upper and lower limit of the steering angle.

In file PID.cpp apart from the Kp, Ki, Kd parameters are initialized, a flag called init is set to True at first(Line 19). In the first iteration, the differential error `d_error` is set to zero. For the following iterations its value equals to the difference between the current cte and the previous cte(Lines 28 - 32). Then the errors are determined following the instructions in the lesson.

