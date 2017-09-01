# PID Controller

### P, I , D effect

P coefficient has a propertional effect to the error and gives instant reaction to error. However, if only that was used it does not really take into consideration Car's inertia and it only is not useful for modeling this. 

D coefficient tracks difference towards the goal we are making and it affects car steering angle in correcting towards the opposite side as car nears its intended goal (cte reduces). This resembles our natural reaction while driving car that as it is reaching towards the center of the road we try adjusting steering wheel in the other direction to straighten the tires.

I coefficient helps systemic errors and in this particular scenario helps car during sharp turns, where even though proportional is good but cummulative error in several steps makes I portion significant and car corrects more quickly

### Selection Process

My current process was very manual , where I started with the base parameters I used in previous lessons about robot movement and right out of the box it was surprisingly doing well. 

I also added pid for throttle, initially I thought of modeling throttle only having P controller, however, speed was getting slightly out of control and then turns became very wild. So I added D component so particularly when due to steering angle and high speed car's change in error is fast, this D component further dampens the speed of the car.

After introducing throttle pid , I further tweaked manually a little bit and submitted it.

I feel lacking model of the car is blocking me from implementing twiddle algorithm for finding best parameters. I could use this simulator as model for my twiddle algorithm however, I felt it would be a very slow implementation and would take a long time and hence did not do that.

Instead I thought of modeling car's model based on collection of information from telemetry. Like collecting , cte, prev_cte and steering angle. And trying to make a linear model of the form cte = linear_function(prev_cte, steering_angle) . That way in my twiddle implementation I could pass PID, Model , twiddle can use PID object to find steering_angle based on cte. And then use Model to find next cte based on cte and steering_angle . Twiddle can run several such steps and optimize on PID coefficient.

However, I later on realized that my collected data has one parameter road direction and which I'm missing and hence wont be able to model car's behavior like I mentioned above from the collected data. 

I could try running car on the straight portions of the track and collect different measurements and then try to model car and that may work but I avoided in this submission if it is not required and its an already due project.