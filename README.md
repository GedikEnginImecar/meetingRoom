# meetingRoom

### Overview of the project

The purpose of the project is to encourage me to explore what I have learnt in terms of programming principles (KISS and SOLID) and to be able to apply them within a "realistic" context.

The abstract of the task was to create an application such that I can control a micro controller and a wired led strip from a webUI, and the user can change the colors.

The project later evolved to be contain the following:

#

##### Design/Production

- Originally was instructed to design a rough sketch of what I wanted the LedBar to look like on pen and paper and ask for someone else to design it properly and produce the parts
  - I wanted to learn a new skill and push the limits of what I can do
- Initially used FreeCad to design the first iteration of the LedBar and asked for key points that might need touch ups
- Later transitioned to SolidWorks Student to even further push myself as it is the industry standard and it is an area that I am interested in
- Learnt to use different tools and practices in SolidWorks, key elements being:
  - Extrude boss/cut
  - Splits based on planes and part sketches
  - Offset to account add tolerance for when fitting parts
  - Using existing CAD Models to help understand the dimensions required of my parts (i.e. battery shield modules and ESP32's)
- Designing parts and assemblies based on dimensions that are known (CAD models) and unclear (parts on hand - measured using a caliper) dimensions

#

##### Software

- Users being able to sign up with different access privileges (owners, supervisors, senior staff, regular staff)
- Users being able to create different rooms that do not exceed their privileges

- Users being able to create meetings in different rooms and dates that do not exceed their privileges
- Uses JWT to verify user
  - Implement accessToken and refreshToken and utilize them in one way or another
- The LEDs could be controlled autonomously from a database (SQLite3 -> PostgreSQL -> Sequelize PostgreSQL) based on the room and when a user created a meeting for (different times in relation to meeting shows different colors/patterns)
- Fully organized codebase in the final iteration, with appropriate middleware, models, controllers and a view.
- Implemented response structures and data transfer objects (example ones only, not for all the files)
- Implemented Swagger documentation (example ones only, not for all the files)

#

##### Micro controllers:

- Can be controlled from both the webUI and a remote (containing another MCU (ESP32))
- A rechargeable battery system in place for the remote/s (Li-ion)
- Instead of being powered by a power supply, the LedBar is powered from a wall plug
- The MCU inside the LedBar uses a DC-DC buck converter to drop the voltage to an appropriate level from the wall plug
- LED on the remote to display the state of the LedBar
- Buttons on remote to control the LedBar and if the remote is on
- Animation for the LedBar using blink, spectrum, morse code (mixture of prebuilt libraries and own code)
- Had to research the specification, ease of use, and suitability of parts I planned on using and had at my disposal
- Looked at using multi threading to delegate different tasks to ESP32, main split between API communications and LED effects/instructing LedBar (for remote)
- Using either (AP changed between the two as project furthered) MCU as a WiFi access point for the other system to connect to for communicating with lower latency and keeping it in a closed system

#

###### Main libraries and tools used:

- SolidWorks
- Ender Creality 3 S1
- Designing parts for a CNC, 3D printer, Drill Router
- Working with aluminum (2mm, 3mm, 5mm)
- Wokwi Simulator (when unable to carry the physical hardware with me)
- MCU (C++)
  - FastLED
  - ESPAsyncWebServer
  - Wifi
  - HTTPClient
  - AsyncTCP
- NodeJS (JS)
  - axios
  - bcrypt
  - cookie
  - cookie-parser
  - cors
  - crypto
  - dotenv
  - express
  - express-validator
  - jsonwebtoken
  - node-cron
  - nodemon
  - pg
  - postgres
  - querystring
  - sequelize
  - swagger-jsdoc
  - swagger-ui-express

#

### Summary

It was an engaging project that forced me to consolidate what I had learnt in theory, and be able to apply it in practice in a realistic environment to develop a project that could in theory be given to a client.
I benefitted from the organizational skills the project forced me to develop from organizing a project blueprint to follow, where I am likely to encounter errors and issues, what tools (software, manufacturing/design and electronic hardware - all of them) are available and which ones are realistic and appropriate to use.
I was able to greatly improve my knowledge and abilities and enjoyed utilizing such a broad skill set and needing to research different fields and subjects to the extend I did.
