# PID Project

Following notes describe how PID parameters were chosen.
Since project didn't allow for an automatic feedback loop without a significant engineering effort expended, I chose parameters manually. My choice was guided by proportional, derivative, integral and total errors, as well as visual judgement of driving path taken by vehicle.

Initially I started with a decreased throttle and only a proportional gain, from which I rapidly built up to default throttle and adding derivative and integral parameters.
Following is a history of parameters I used, in chronological order, along with remarks regarind associated errors and vehicle behaviour. Parameters values that lead to vehicle driving off the track in first few meters aren't included below.

#### Parameters: Kp = 0.1, Kd = 0, Ki = 0, throttle = 0.1
Typical errors:
- p_error - 0.5 to 1.2
- d_error - 0.01 to 0.05
- i_error - 1250 after crossing the bridge

#### Parameters: Kp = 0.4, Kd = 0, Ki = 0, throttle = 0.1
Typical errors:
- p_error - 0.5 to 1.2
- d_error - 0.01 to 0.05
- i_error - 350 after crossing the bridge

#### Parameters: Kp = 0.4, Kd = 1, Ki = 0, throttle = 0.2
Typical errors:
- p_error - 0.2 to 0.4
- d_error - 0.1 to 1
- i_error - 210 after crossing the bridge
Noticeable wobbling

#### Parameters: Kp = 0.4, Kd = 1, Ki = 0, throttle = 0.3 (project default)
Typical errors:
- p_error - 0.2 to 1
- d_error - 0.05 to 0.2
- i_error - 160 after crossing the bridge
Very noticeable wobbling

#### Parameters: Kp = 0.1, Kd = 1, Ki = 0, throttle = 0.3 (project default)
Typical errors:
- p_error - 0.1 to 0.3
- d_error - 0.001 to 0.02
- i_error - 500 after crossing the bridge
Reasonably smooth ride

#### Ki at 0.1 and 0.01 leads vehicle to drive off the track very quickly.

#### Parameters: Kp = 0.1, Kd = 1, Ki = 0.001, throttle = 0.3 (project default)
Typical errors:
- p_error - 0.2 to 0.5
- d_error - 0.01 to 0.05
- i_error - 35 after crossing the bridge
Reasonably smooth ride

#### Parameters: Kp = 0.1, Kd = 1, Ki = 0.001, throttle = 0.3 (project default)
Vehicle can navigate whole track succesfully at speeds ~32mph, although on some curves it's a close call.
Total error: 82

#### Parameters: Kp = 0.1, Kd = 1, Ki = 0.002, throttle = 0.3 (project default)
Vehicle can navigate whole track succesfully at speeds ~32mph, somewhat better than with Ki = 0.001
Total error: 29

Observing that car stays close to curb on sharp turns, tried bumping up Kp a bit. This led to better behaviour at turns but too much overshoot on straight roads.
Therefore I tried bumping Kd instead to 2. This led to a significantly better driving. Curves still aren't driven dead in the middle, so I'm sure there is room for further improvements, but overall the driving profile is fairy nice.

### Final parameters: Kp = 0.1, Kd = 2.0, Ki = 0.002, throttle = 0.3 (project default)
