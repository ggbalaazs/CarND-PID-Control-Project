# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Description

This project is about implementing a PID controller in C++ to maneuver the vehicle around the track. The simulator will provide the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle.

## Reflection

PID is a commonly used controller which uses the error between desired and measured values to provide a 3-term feedback for minimizing the error in the long run. In this project the cross track error (difference between road center and actual position) is the target to be minimized. The controller should adjust the steering value in the first place, but throttle can be also changed. Term P is the proportional feedback of the cross track error: the larger the error, the larger the proportional correction. This was the key factor to steer back the vehicle to its central position. Term I is the integral component that makes adjustment based on many recent errors. It is supposed to correct possible offset errors over time. The integral term was not really a necessity in this project, the simulator has no offset errors that need to be handled. Term D is the derivative term that takes into account the rate of change of errors. This works against the proportional term: the more rapid the change, the greater its dampening effect. A carefully chosen proportional term was enough in itself to recover central position when driving in straight line. But as soon as there was change in driving direction, the car was starting to oscillate after the turn. With additional derivative term the dampening stopped the oscillation.

At first I experimented with Kp value, Ki and Kd was set to 0. The effect of small errors on steering was too much, exponential diminishing seemed like a good idea. Steering value needed to be limited as well, 0.2 radians was the starting value. I set constant throttle to 0.3 and manually tuned parameters of Kp and the exponent. I settled for the value 0.18 as Kp.

The car went well until first turn, but after that derivative component was required to dampen oscillation. So I manually tuned Kd. Setting Kd to 6.0 was sufficient.

There was not any constant error that needed to be integrated out, but for small residual errors integral component may be still useful. Anyway I added a very small Ki, 0.0001.

The second turn on the map needed higher steering limit. Later I increased the maximum speed and added braking at near-limit steering.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)
