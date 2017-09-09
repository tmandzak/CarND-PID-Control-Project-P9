# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---


## Reflection

After the PID Control solution is implemented the next step is to tune it's parameters so that the vehicle is able to drive successfully around the track. In this part I'm going to describe my experience with tuning these parameters.

* Speed and Throttle

First I set the ultimate speed to 10 mph. Changing the speed will demand to retune other parameters.
Throttle was set to 0.3 for actual speed less then 10 mph and 0 otherwise. This way the speed was kept around 10 mph after it was reached.

* Proportional (P) component

This component looked to be the most influencial at start of the track, so it was the first to be tuned through it's Kd parameter. Other components were set to be 0. Among values tested (1, 0.5, 0.2, 0.1) Kp = 0.1 led to the most satisfactory movement along the stright part of the track. Decreasing Kp let to decrease the amplitude of the vehicle movement along the center line, but still the vehicle got out of the track at the first turn. I decided to approach this by tuning the differential component.

* Differential (D) component

The next step was to tune Differential component through it's Kd parameter. Keeping Kp = 0.1 and setting Kd = 0.1 did just enough:
the vehicle was able to treat turns well and to drive around the track not leaving the drivable portion of the surface. 
Along the way average squared CTE was calculated at each step (as in the lesson's example of Twiddle process). For step 800
it was equal 1.08 and I decided to try imroving on it by tuning Integral component.

* Integral (I) component

The next step was to tune Integral component through it's Ki parameter. Keeping Kp = 0.1 and Kd = 0.1 I tested following values of 
Ki: 0.1, 0.01, 0.001, 0.0001 and 0.00005. First two values led the vehicle off trackby increasing the amplitude. 
Values 0.001, 0.0001 and 0.00005 led to the following values of average squared CTE at step 800 correspondingly: 1.30, 0.96, 1.00.

* Final set of parameters

For ultimate Speed = 10 mph taking into account considerations above Kp = 0.1, Ki = 0.0001, Kd = 0.1. 

* Opportunities for improvement

1. The set of parameters above can be treated as an input for automated Twiddle process that would lead to a better average squared CTE.
2. Additional PID controller can be implemented for Throttle so that speed has more constant value along the way.
3. Investigate tuning process for higher speed values.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
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

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

