# Velocity-Vanguards

**Bot Name: Vector**

**1. Photos:** Check Team_Gallery for the crazy pics of our XLR8 journey! 

**2. What Makes Our Bot Different from the Rest**

While many teams utilized similar sensors like the MPU6050 gyroscope, ultrasonic sensors, and servo motors, our bot stood out due to the following features:

a. Two-Part Chassis Design: We split the chassis into two parts—left and right—which improved stability and torque distribution. This design allowed the bot to traverse uneven terrain and cross obstacles more effectively. Unlike other bots that struggled on challenging surfaces, ours could maintain control on inclines and rough tracks.

b. 360-Degree Obstacle Detection Without Servo Motor: While most teams used a servo motor to rotate the ultrasonic sensor for autonomous navigation, we took a different approach. We programmed our bot to rotate itself to scan the environment, providing 360-degree coverage. This eliminated the need for an additional servo motor, simplifying the design and reducing potential points of failure, all while maintaining accurate obstacle detection.

**3. Motivation for Our Idea and XLR8 Journey**

The idea for our bot was born from the need for a robust solution that could effectively navigate unpredictable terrain while maintaining stability and control. Traditional robots tend to struggle with balance when encountering uneven surfaces, leading to inefficiencies and potential breakdowns. We realized that a rigid, single-body chassis was a limitation in such environments. Our goal was to design a bot that could dynamically adjust to the terrain, making it more versatile in real-world scenarios.

By incorporating a split chassis with a hinge in the center, we allowed each half of the bot to move independently. This provided superior adaptability on rough terrains, allowing one side of the bot to react to obstacles differently than the other, improving both balance and control. Through our journey in the XLR8 competition, we iterated on this design, refining the hinge mechanism to ensure it functioned smoothly under different loads and conditions. The process also helped us dive deeper into integrating sensors for more accurate obstacle detection and response.

We participated in XLR8 because we were genuinely enthusiastic about exploring the electrical aspects of the program. Electrical systems and circuitry are among our favorite topics, and the opportunity to dive deeper into these areas was incredibly exciting. Our involvement in XLR8 allowed us to immerse ourselves in hands-on experiences, expanding our knowledge and skills in a field we’re passionate about. This engagement not only enhanced our technical expertise but also fueled our curiosity and love for learning about the intricacies of electrical engineering an robotics.
We also attempted two electrical problem statements of AUV and MRT TEam which required quite brainstorming but after successful run for the both, our satisfaction was on another level.


**4. Resources Used**

    Hardware:

    1. Raspberry Pi Pico W for processing and wireless control
    2. MPU6050 Gyroscope for motion tracking and orientation
    3. Ultrasonic Sensor for obstacle detection and navigation
    4. L298N Motor Driver for controlling the motors
    5. 100 RPM Motors to drive the wheels
    6. RGB LEDs to signal movement direction (based on AUV challenge)
    7. Two-Part Modular Acrylic Chassis for better stability and obstacle-crossing capabilities
    8. Li-ion Battery Pack (7.4V) to power the entire system
    
    Software:

    1. Arduino IDE for coding the Raspberry Pi Pico W
    2. Pre-installed libraries:
        WiFi.h for wireless communication
        Wire.h for I2C communication with the MPU6050
        ESP8266WiFi.h for connecting ESP01 if necessary
        math.h for motion and direction calculations
    
    Online Resources and Guides:

    1. Raspberry Pi Pico W official documentation
    2. Tutorials on MPU6050 and ultrasonic sensor integration
    3. Support and mentorship from the ERC Club, IIT Bombay
    4. Our XLR8 Mentor: Animesh Jain

    
**5. Mechanical Design:**

The CAD file has been attached here with name XLR8_Velocity-Vanguards.dxf
The chassis was designed with two distinct sections:

Left and Right parts, each holding its own motor and electronics, connected at the center.
This modular approach ensures:
1. Improved load distribution for better balance and handling.
2. Enhanced stability during turns and when navigating inclines or rough surfaces.
3. The bot’s ability to cross obstacles more easily by flexing its chassis.
4. This design has the added advantage of offering better control and responsiveness while reducing mechanical complexity (as no servo motor is required for sensor rotation).

**6. Electrical Design (Circuit Diagram):**

The electrical design includes:

1. Raspberry Pi Pico W acting as the controller and wireless communication hub.
2. MPU6050 Gyroscope positioned centrally for accurate tilt and orientation tracking.
3. Ultrasonic sensor mounted in the front for obstacle detection, enabling 360-degree navigation by rotating the bot instead of using a servo motor. (for MRT Problem Statement)
4. L298N Motor Driver connected to two 100 RPM motors on each side, each driving one side of the two-part chassis.
5. RGB LEDs connected to signal the bot's direction (as per the AUV challenge).
6. Li-ion battery pack powering the entire system with regulated voltage and grounding.

The circuit diagram can be found in the folder named 'Electrical_Design' in this repository
    
**7. Code for the RPi Pico W**

Our code handles:

1. IMU (gyroscope) data processing to track orientation and adjust motor speeds accordingly.
2. Obstacle detection using the ultrasonic sensor: The bot rotates itself to scan for obstacles, offering 360-degree coverage without requiring a servo motor. 
3. Motor control: Based on the sensor inputs, the bot adjusts its movement speed and direction to navigate autonomously. For this model two levels of speed were set.
4. RGB LED feedback: RGB LEDs light up in different colors to indicate the direction of movement (forward, reverse, left, right).
5. Wireless control via the Raspberry Pi Pico W for real-time commands and feedback with delay time of 100 ms

The Code files for Autonomous Navigation and for XLR8 Run with RGB light can be found in the Code Folder in this Repository

   


**8. Help Received from Mentors**

Our mentors from the ERC Club, IIT Bombay, played a key role in helping us overcome several technical challenges. They provided guidance on:
Circuit design: Ensuring efficient power management to keep the bot running longer on battery power.
Debugging our problems late nights
Answering our silly quesitons
Perfecting us in Soldering
Their assistance helped us fine-tune the bot for both autonomous navigation and manual control, making it highly versatile.

Our XLR8 Mentor Animesh Jain helped us in various factors:

As soon as the codified session was done he suggested us to get laser cutting of the chassis to avoid unnecessary rush, he himself accompanied us for laser cutting and explained how the machine work and what all precaution that we need to take
He supported us on the idea of two part design and told about necessary consideration that we must take
Once after completion, when our bot was toppling we changed the design and lowered the COM
His motivation to wind up earlier and look forward to solve problem statement for getting into the Tech Teams kept us going thorugh the entire XLR8 Journey
His tips and guidelines on how to control our bot on each and every obstacle, when to slow down or when to spped up were remarkable
