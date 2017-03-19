//
//  DJIRemoteControllerBaseTypes.h
//  DJISDK
//
//  Copyright © 2016, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DJI_RC_CONTROL_CHANNEL_SIZE     (4)

NS_ASSUME_NONNULL_BEGIN

/*********************************************************************************/
#pragma mark - Data Structs and Enums
/*********************************************************************************/

#pragma pack(1)

/*********************************************************************************/
#pragma mark DJIRemoteControllerMode
/*********************************************************************************/

/**
 *  Remote Controller mode of operation can be normal (single RC connected to
 *  aircraft), master, slave, or unknown.
 */
typedef NS_ENUM (uint8_t, DJIRemoteControllerMode){
    /**
     *  Remote Controller is a master (will route a connected slave Remote
     *  Controller's commands to the aircraft).
     */
    DJIRemoteControllerModeMaster,
    /**
     *  Remote Controller is currently a slave Remote Controller (sends commands
     *  to aircraft through a master Remote Controller).
     */
    DJIRemoteControllerModeSlave,
    /**
     *  Remote Controller is unconnected to another Remote Controller.
     */
    DJIRemoteControllerModeNormal,
    /**
     *  The Remote Controller's mode is unknown.
     */
    DJIRemoteControllerModeUnknown,
};

/*********************************************************************************/
#pragma mark DJIRemoteControllerModeState
/*********************************************************************************/

/**
 *  Remote Controller's control channel.
 */
typedef struct {
    /**
     *  Remote Controller mode.
     */
    DJIRemoteControllerMode mode;
    
    /**
     *  'YES' If connected.
     */
    BOOL isConnected;
} DJIRemoteControllerModeState;

/*********************************************************************************/
#pragma mark DJIRCID
/*********************************************************************************/

/**
 *  Remote Controller's unique identification number. This is given to each Remote
 *  Controller during manufacturing and cannot be changed.
 */
typedef uint32_t DJIRCID;

/*********************************************************************************/
#pragma mark DJIRCSignalQualityOfConnectedRC
/*********************************************************************************/

/**
 *  Signal quality of a connected master or slave Remote Controller in percent [0, 100].
 */
typedef uint8_t DJIRCSignalQualityOfConnectedRC;

/*********************************************************************************/
#pragma mark DJIRCControlStyle
/*********************************************************************************/

/**
 *  Remote Controller's control style.
 */
typedef NS_OPTIONS (uint8_t, DJIRCControlStyle){
    /**
     *  Remote Controller uses Japanese controls (also known as Mode 1). In this
     *  mode the left stick controls Pitch and Yaw, and the right stick controls
     *  Throttle and Roll.
     */
    RCControlStyleJapanese,
    /**
     *  Remote Controller uses American controls (also known as Mode 2). In this
     *  mode the left stick controls Throttle and Yaw, and the right stick
     *  controls Pitch and Roll.
     */
    RCControlStyleAmerican,
    /**
     *  Remote Controller uses Chinese controls (also know as Mode 3). In this
     *  mode the left stick controls Pitch and Roll, and the right stick 
     *  controls Throttle and Yaw.
     */
    RCControlStyleChinese,
    /**
     *  Stick channel mapping for Roll, Pitch, Yaw and Throttle can be customized.
     */
    RCControlStyleCustom,
    /**
     *  Default Remote Controller controls and settings for the slave Remote
     *  Controller.
     */
    RCSlaveControlStyleDefault,
    /**
     *  Slave remote controller stick channel mapping for Roll, Pitch, Yaw and
     *  Throttle can be customized.
     */
    RCSlaveControlStyleCustom,
    /**
     *  The Remote Controller's control style is unknown.
     */
    RCControlStyleUnknown,
};

/*********************************************************************************/
#pragma mark DJIRCControlChannelName
/*********************************************************************************/

/**
 *  Remote Controller control channels. These will be used in RC Custom Control Style. See
 *  `RCControlStyleCustom` and `RCSlaveControlStyleCustom` for more information.
 *
 */
typedef NS_ENUM (uint8_t, DJIRCControlChannelName){
    /**
     *  Not mapped.
     */
    DJIRCControlChannelNameNone,
    /**
     *  Throttle control channel.
     */
    DJIRCControlChannelNameThrottle,
    /**
     *  Pitch control channel.
     */
    DJIRCControlChannelNamePitch,
    /**
     *  Roll control channel.
     */
    DJIRCControlChannelNameRoll,
    /**
     *  Yaw control channel.
     */
    DJIRCControlChannelNameYaw,
};

/*********************************************************************************/
#pragma mark DJIRCControlChannel
/*********************************************************************************/

/**
 *  Remote Controller's control channel.
 */
typedef struct
{
    /**
     *  Name of the control channel. The format of this
     *  is `DJI_RC_CONTROL_CHANNEL_xxx`. The default is American.
     */
    DJIRCControlChannelName channel;
    
    /**
     *  The control channel's settings will be reversed.
     *  For example, for the throttle, the joystick is moved up or
     *  down. If the control channel was reversed, the same motion
     *  that was once used for up would now move the aircraft
     *  down, and the same motion that was once used for down would
     *  now move the aircraft up.
     */
    BOOL reverse;
} DJIRCControlChannel;

/*********************************************************************************/
#pragma mark DJIRCControlMode
/*********************************************************************************/

/**
 *  Remote Controller's control mode.
 */
typedef struct
{
    /**
     *  The control style to which the Remote Controller is set.
     */
    DJIRCControlStyle controlStyle;
    
    /**
     *  Setting controls for each of the channels.
     */
    DJIRCControlChannel controlChannel[DJI_RC_CONTROL_CHANNEL_SIZE];
} DJIRCControlMode;

/*********************************************************************************/
#pragma mark DJIRCRequestGimbalControlResult
/*********************************************************************************/

/**
 *  Result when a slave Remote Controller requests permission to control the gimbal.
 */
typedef NS_OPTIONS (uint8_t, DJIRCRequestGimbalControlResult){
    /**
     *  The master Remote Controller agrees to the slave's request.
     */
    RCRequestGimbalControlResultAgree,
    /**
     *  The master Remote Controller denies the slave's request. If the slave
     *  Remote Controller wants to control the gimbal, it must send a request to
     *  the master Remote Controller first. Then the master Remote Controller
     *  can decide to approve or deny the request.
     */
    RCRequestGimbalControlResultDeny,
    /**
     *  The slave Remote Controller's request timed out.
     */
    RCRequestGimbalControlResultTimeout,
    /**
     *  The master Remote Controller authorized the slave request to control the
     *  gimbal.
     */
    RCRequestGimbalControlResultAuthorized,
    /**
     *  The slave Remote Controller's request is unknown.
     */
    RCRequestGimbalControlResultUnknown,
};

/*********************************************************************************/
#pragma mark DJIRCControlPermission
/*********************************************************************************/

/**
 *  Remote Controller's control permission.
 */
typedef struct
{
    /**
     *  TRUE if the Remote Controller has permission
     *  to control the gimbal yaw.
     */
    bool hasGimbalYawControlPermission;
    
    /**
     *  TRUE if the Remote Controller has permission
     *  to control the gimbal roll.
     */
    bool hasGimbalRollControlPermission;
    
    /**
     *  TRUE if the Remote Controller has permission
     *  to control the gimbal pitch.
     */
    bool hasGimbalPitchControlPermission;
    
    /**
     *  TRUE if the Remote Controller has permission
     *  to control camera playback.
     */
    bool hasPlaybackControlPermission;
    
    /**
     *  TRUE if the Remote Controller has permission
     *  to record video with the camera.
     */
    bool hasRecordControlPermission;
    
    /**
     *  TRUE if the Remote Controller has permission
     *  to take pictures with the camera.
     */
    bool hasCaptureControlPermission;
    
} DJIRCControlPermission;

/*********************************************************************************/
#pragma mark DJIRCGimbalControlSpeed
/*********************************************************************************/

/**
 *  Remote Controller's gimbal control speed.
 */
typedef struct
{
    /**
     *  Gimbal's pitch speed with range [0,100].
     */
    uint8_t pitchSpeed;
    
    /**
     *  Gimbal's roll speed with range [0,100].
     */
    uint8_t rollSpeed;
    
    /**
     *  Gimbal's yaw speed with range [0,100].
     */
    uint8_t yawSpeed;
} DJIRCGimbalControlSpeed;

/*********************************************************************************/
#pragma mark DJIRCToAircraftPairingState
/*********************************************************************************/

/**
 *  Remote Controller pairing state.
 */
typedef NS_ENUM (uint8_t, DJIRCToAircraftPairingState){
    /**
     *  The Remote Controller is not pairing.
     */
    DJIRCToAircraftPairingStateNotParing,
    /**
     *  The Remote Controller is currently pairing.
     */
    DJIRCToAircraftPairingStateParing,
    /**
     *  The Remote Controller's pairing was completed.
     */
    DJIRCToAircraftPairingStateCompleted,
    /**
     *  The Remote Controller's pairing state is unknown.
     */
    DJIRCToAircraftPairingStateUnknown,
};

/*********************************************************************************/
#pragma mark DJIRCJoinMasterResult
/*********************************************************************************/

/**
 *  Result when a slave Remote Controller tries to join
 *  a master Remote Controller.
 */
typedef NS_ENUM (uint8_t, DJIRCJoinMasterResult){
    /**
     *  The slave Remote Controller's attempt to join
     *  the master Remote Controller was successful.
     */
    DJIRCJoinMasterResultSuccessful,
    /**
     *  The slave Remote Controller's attempt to join
     *  the master Remote Controller was unsuccessful
     *  due to a password error.
     */
    DJIRCJoinMasterResultPasswordError,
    /**
     *  The slave Remote Controller's attempt to join
     *  the master Remote Controller was rejected.
     */
    DJIRCJoinMasterResultRejected,
    /**
     *  The slave Remote Controller's attempt to join
     *  the master Remote Controller was unsuccesful
     *  because the master Remote Controller is at the
     *  maximum number of slaves it can have.
     */
    DJIRCJoinMasterResultReachMaximum,
    /**
     *  The slave Remote Controller's attempt to join
     *  the master Remote Controller was unsuccessful
     *  because the request timed out.
     */
    DJIRCJoinMasterResultResponseTimeout,
    /**
     *  The result of the slave Remote Controller's
     *  attempt to join the master Remote Controller
     *  is unknown.
     */
    DJIRCJoinMasterResultUnknown
};

/*********************************************************************************/
#pragma mark DJIRCBatteryInfo
/*********************************************************************************/

/**
 *  Remote Controller's battery info.
 */
typedef struct
{
    /**
     *  The remaining power in the Remote Controller's
     *  battery in milliamp hours (mAh).
     */
    uint32_t remainingEnergyInMAh;
    
    /**
     *  The remaining power in the Remote Controller's
     *  battery as a percentage in the range of [0, 100].
     */
    uint8_t remainingEnergyInPercent;
} DJIRCBatteryInfo;

/*********************************************************************************/
#pragma mark DJIRCGpsTime
/*********************************************************************************/

/**
 *  Remote Controller's GPS time.
 */
typedef struct
{
    /**
     *  Hour value of Remote Controller's GPS time.
     */
    uint8_t hour;
    
    /**
     *  Minute value of Remote Controller's GPS time.
     */
    uint8_t minute;
    
    /**
     *  Second value of Remote Controller's GPS time.
     */
    uint8_t second;
    
    /**
     *  Year value of Remote Controller's GPS time.
     */
    uint16_t year;
    
    /**
     *  Month value of Remote Controller's GPS time.
     */
    uint8_t month;
    
    /**
     *  Day value of Remote Controller's GPS time.
     */
    uint8_t day;
} DJIRCGpsTime;

/*********************************************************************************/
#pragma mark DJIRCGPSData
/*********************************************************************************/

/**
 *  Remote Controller's GPS data. Only Inspire and M100 Remote Controllers have GPS.
 */
typedef struct
{
    /**
     *  The Remote Controller's GPS time.
     */
    DJIRCGpsTime time;
    
    /**
     *  The Remote Controller's GPS latitude
     *  in degrees.
     */
    double latitude;
    
    /**
     *  The Remote Controller's GPS longitude
     *  in degrees.
     */
    double longitude;
    
    /**
     *  The Remote Controller's speed in the East direction in meters/second. A
     *  negative speed means the Remote Controller is moving in the West direction.
     */
    float speedEast;
    
    /**
     *  The Remote Controller's speed in the North direction in meters/second. A
     *  negative speed means the Remote Controller is moving in the South direction.
     */
    float speedNorth;
    
    /**
     *  The number of GPS sattelites the Remote Controller detects.
     */
    int satelliteCount;
    
    /**
     *  The the margin of error, in meters, for the
     *  GPS location.
     */
    float accuracy;
    
    /**
     *  YES if the GPS data is valid. The data is not valid if there are too few
     *  satellites or the signal strength is too low.
     */
    BOOL isValid;
} DJIRCGPSData;

/*********************************************************************************/
#pragma mark DJIRCGimbalControlDirection
/*********************************************************************************/

/**
 *  Defines what the Gimbal Dial (upper left wheel on the Remote Controller) will control.
 */
typedef NS_ENUM (uint8_t, DJIRCGimbalControlDirection){
    /**
     *  The upper left wheel will control the gimbal's pitch.
     */
    DJIRCGimbalControlDirectionPitch,
    /**
     *  The upper left wheel will control the gimbal's roll.
     */
    DJIRCGimbalControlDirectionRoll,
    /**
     *  The upper left wheel will control the gimbal's yaw.
     */
    DJIRCGimbalControlDirectionYaw,
};

/*********************************************************************************/
#pragma mark DJIRCHardwareRightWheel
/*********************************************************************************/

/**
 *  Current state of the Camera Settings Dial (upper right wheel on the Remote
 *  Controller).
 */
typedef struct
{
    /**
     * YES if right wheel present.
     */
    BOOL isPresent;
    
    /**
     *  YES if wheel value has changed.
     */
    BOOL wheelChanged;
    
    /**
     *  YES if wheel is being pressed.
     */
    BOOL wheelButtonDown;
    
    /**
     *  YES if wheel is being turned in a clockwise direction.
     */
    BOOL wheelDirection;
    
    /**
     *  Wheel value in the range of [0, 1320]. The value represents the
     *  difference in an operation.
     */
    uint8_t value;
} DJIRCHardwareRightWheel;

/*********************************************************************************/
#pragma mark DJIRCHardwareLeftWheel
/*********************************************************************************/

/**
 *  Remote Controller's left wheel.
 */
typedef struct
{
    /**
     *  Gimbal Dial's (upper left wheel) value in the range of [-660,660], where
     *  0 is untouched and positive is turned in the clockwise direction.
     */
    int value;
} DJIRCHardwareLeftWheel;

/*********************************************************************************/
#pragma mark DJIRCHardwareTransformationSwitchState
/*********************************************************************************/

/**
 *  Transformation Switch position states.
 */
typedef NS_ENUM (uint8_t, DJIRCHardwareTransformationSwitchState){
    /**
     *  Retract landing gear switch state.
     */
    DJIRCHardwareTransformationSwitchStateRetract,
    /**
     *  Deploy landing gear switch state.
     */
    DJIRCHardwareTransformationSwitchStateDeploy
};

/*********************************************************************************/
#pragma mark DJIRCHardwareTransformSwitch
/*********************************************************************************/

/**
 *  Transformation Switch position. The Transformation Switch is around the
 *  Return To Home Button on Inspire, Inspire 1 and M100 Remote Controllers, and
 *  controls the state of the aircraft's landing gear.
 */
typedef struct
{
    /**
     *  YES if the Transformation Switch present.
     */
    BOOL isPresent;
    
    /**
     *  Current transformation switch state.
     */
    DJIRCHardwareTransformationSwitchState transformationSwitchState;
    
} DJIRCHardwareTransformationSwitch;

/*********************************************************************************/
#pragma mark DJIRemoteControllerFlightModeSwitchPosition
/*********************************************************************************/
/**
 *  Remote Controller Flight Mode switch position.
 */
typedef NS_ENUM (uint8_t, DJIRemoteControllerFlightModeSwitchPosition){
    /**
     *  Position One. For all products except Mavic Pro, this is the left most
     *  position of the flight mode switch on a remote controller from the
     *  perspective of the pilot. For example, on a Phantom 4 remote controller,
     *  Position One is labeled "A".
     *  For the Mavic Pro, this is the position that is furthest away from the
     *  pilot and labeled "Sport".
     */
    DJIRemoteControllerFlightModeSwitchPositionOne,
    /**
     *  Position Two. For all products except Mavic Pro, this is the middle
     *  position of the flight mode switch on a remote controller from the
     *  perspective of the pilot. For example, on a Phantom 4 remote controller,
     *  Position Two is labeled "S".
     *  For the Mavic Pro, this is the position that is closest to the pilot
     *  (the P position).
     */
    DJIRemoteControllerFlightModeSwitchPositionTwo,
    /**
     *  Position Three. For all products except Mavic Pro, this is the right
     *  most position of the flight mode switch on a remote controller from the
     *  perspective of the pilot. For example, on a Phantom 4 remote controller,
     *  Position Two is labeled "P".
     *  The Mavic Pro does not have a third position for the flight mode switch.
     */
    DJIRemoteControllerFlightModeSwitchPositionThree,
};

/*********************************************************************************/
#pragma mark DJIRCHardwareButton
/*********************************************************************************/

/**
 *  Remote Controller has numerous momentary push buttons, which will use this state.
 */
typedef struct
{
    /**
     * YES if Hardware button present.
     */
    BOOL isPresent;
    
    /**
     *  YES if button is pressed down.
     */
    BOOL buttonDown;
} DJIRCHardwareButton;

/*********************************************************************************/
#pragma mark DJIRCHardwareJoystick
/*********************************************************************************/

/**
 *  Remote Controller's joystick
 */
typedef struct
{
    /**
     *  Joystick's channel value in the range of [-660, 660]. This
     *  value may be different for the aileron, elevator, throttle, and rudder.
     */
    int value;
} DJIRCHardwareJoystick;

/*********************************************************************************/
#pragma mark DJIRCFiveDButton
/*********************************************************************************/

/**
 *  Movement direction of the remote controller's 5D button.
 */
typedef NS_ENUM(NSUInteger, DJIRCFiveDButtonDirection) {
    /**
     *  Button has no movement in either the vertical direction or the
     *  horizontal direction.
     */
    DJIRCFiveDButtonDirectionMiddle,
    /**
     *  Button is moved in the positive direction.
     */
    DJIRCFiveDButtonDirectionPositive,
    /**
     *  Button is moved in the negative direction.
     */
    DJIRCFiveDButtonDirectionNegative,
};

/**
 *  State of the 5D button on the remote controller.
 *  Vertical movement, horizontal movment and if it is pressed are not exclusive.
 */
typedef struct{
    
    /**
     * YES if 5D button is present.
     */
    BOOL isPresent;
    
    /**
     *  The movement in the vertical direction of the 5D button.
     *  Up is the positive direction and down is the negative direction.
     */
    DJIRCFiveDButtonDirection verticalMovement;
    
    /**
     *  The movement in the horizontal direction of the 5D button.
     *  Right is the positive direction and left is the negative direction.
     */
    DJIRCFiveDButtonDirection horizontalMovement;
    
    /**
     *  If the 5D button is pressed down.
     */
    BOOL buttonPressed;
}DJIRCFiveDButton;

/*********************************************************************************/
#pragma mark DJIRCHardwareState
/*********************************************************************************/

/**
 *  Remote Controller's current state.
 */
typedef struct
{
    /**
     *  Left joystick 's horizontal value.
     */
    DJIRCHardwareJoystick leftHorizontal;
    
    /**
     *  Left joystick 's vertical value.
     */
    DJIRCHardwareJoystick leftVertical;
    
    /**
     *  Right joystick 's Vertical value.
     */
    DJIRCHardwareJoystick rightVertical;
    
    /**
     *  Right joystick 's Horizontal value.
     */
    DJIRCHardwareJoystick rightHorizontal;
    
    /**
     *  Current state of the upper left wheel on the Remote Controller (Gimbal Dial).
     */
    DJIRCHardwareLeftWheel leftWheel;
    
    /**
     *  Current state of the upper right wheel on the Remote Controller (Camera Settings Dial).
     */
    DJIRCHardwareRightWheel rightWheel;
    
    /**
     *  Current state of the Transformation Switch on the Remote Controller.
     */
    DJIRCHardwareTransformationSwitch transformationSwitch;
    
    /**
     *  Current position of the Flight Mode Switch on the Remote Controller.
     */
    DJIRemoteControllerFlightModeSwitchPosition flightModeSwitch;
    
    /**
     *  Current state of the Return To Home Button.
     */
    DJIRCHardwareButton goHomeButton;
    
    /**
     *  Current state of the Video Recording Button.
     */
    DJIRCHardwareButton recordButton;
    
    /**
     *  Current state of the Shutter Button.
     */
    DJIRCHardwareButton shutterButton;
    
    /**
     *  Current state of the Playback Button. The Playback Button is not 
     *  supported on Phantom 4 remote controllers.
     */
    DJIRCHardwareButton playbackButton;
    
    /**
     *  Current state of the Pause Button. The Pause button is only supported on
     *  Phantom 4 remote controllers.
     */
    DJIRCHardwareButton pauseButton;
    
    /**
     *  Current state of custom button 1 (left Back Button).
     */
    DJIRCHardwareButton customButton1;
    
    /**
     *  Current state of custom button 2 (right Back Button).
     */
    DJIRCHardwareButton customButton2;
    
    /**
     *  Current state of the 5D button. The button can be moved up, down, left
     *  and right and can be pressed. The 5D button is only supported on Mavic
     *  Pro remote controllers.
     */
    DJIRCFiveDButton fiveDButton;
} DJIRCHardwareState;

/*********************************************************************************/
#pragma mark DJIRCRemoteFocusControlType
/*********************************************************************************/

/**
 *  Remote Focus Control Type
 */
typedef NS_ENUM (uint8_t, DJIRCRemoteFocusControlType){
    /**
     *  Control Aperture.
     */
    DJIRCRemoteFocusControlTypeAperture,
    /**
     *  Control Focal Length.
     */
    DJIRCRemoteFocusControlTypeFocalLength,
};

/*********************************************************************************/
#pragma mark DJIRCRemoteFocusControlDirection
/*********************************************************************************/

/**
 *  Remote Focus Control Direction
 */
typedef NS_ENUM (uint8_t, DJIRCRemoteFocusControlDirection){
    /**
     *  Clockwise
     */
    DJIRCRemoteFocusControlDirectionClockwise,
    /**
     *  CounterClockwise
     */
    DJIRCRemoteFocusControlDirectionCounterClockwise,
};

/*********************************************************************************/
#pragma mark DJIRemoteControllerChargeMobileMode
/*********************************************************************************/
/**
 *  Modes to charge the iOS mobile device. 
 *  Only supported by Inspire 2.
 */
typedef NS_ENUM (uint8_t, DJIRemoteControllerChargeMobileMode){
    /**
     *  The remote controller does not charge the mobile device.
     */
    DJIRemoteControllerChargeMobileModeNever,
    /**
     *  The remote controller charges the mobile device until the the mobile
     *  device is fully charged.
     */
    DJIRemoteControllerChargeMobileModeAlways,
    /**
     *  The remote controller charges the mobile device in an intelligent mode: 
     *  The remote controller starts charging when the mobile device's battery
     *  is lower then 20% and stops charging when the mobile device's battery
     *  is above 50%.
     */
    DJIRemoteControllerChargeMobileModeIntelligent,
    /**
     *  Unknown.
     */
    DJIRemoteControllerChargeMobileModeUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCRemoteFocusState
/*********************************************************************************/

/**
 Remote Controller's Remote Focus State
 
 The focus product has one dial (focus control) that controls two separate parts
 of the camera: focal length and aperture. However it can only control one of
 these at any one time and is an absolute dial, meaning that a specific rotational
 position of the dial corresponds to a specific focal length or aperture.
 
 This means that whenever the dial control mode is changed, the dial first has to be
 reset to the new mode's previous dial position before the dial can be used to adjust
 the setting of the new mode.
 
 Example workflow:<br/><ol>
 <li>Use dial to set an Aperture of f2.2</li>
 <li>Change dial control mode to focal length (set `DJIRCRemoteFocusControlType`)</li>
 <li>Use the dial to change the focal length</li>
 <li>Change dial control mode back to aperture<ul>
 <li>set `DJIRCRemoteFocusControlType`</li>
 <li>`isFocusControlWorks` will now be NO</li>
 </ul>
 </li>
 <li>Adjust dial back to f2.2<ul>
 <li>`DJIRCRemoteFocusControlDirection` is the direction the dial should be rotated</li>
 <li>`isFocusControlWorks` will become YES when set back to f2.2</li>
 </ul>
 </li>
 <li>Now the dial can be used to adjust the aperture.
 </ol>
 
 */
typedef struct
{
    /**
     *
     *  YES if the focus control works. The control can be either changing the
     *  Aperture or Focal Length. If it is NO, follow the
     *  `DJIRCRemoteFocusControlDirection` to rotate the Remote Focus Device
     *  until it turns to YES again.
     */
    BOOL isFocusControlWorks;
    
    /**
     *
     *  Remote Focus Control Type
     */
    DJIRCRemoteFocusControlType controlType;
    
    /**
     *
     *  Remote Focus Control Direction. Use this with the `isFocusControlWorks`
     *  value. It will give you the correct rotation direction when
     *  `isFocusControlWorks` is NO.
     */
    DJIRCRemoteFocusControlDirection direction;
    
} DJIRCRemoteFocusState;

#pragma pack()

/*********************************************************************************/
#pragma mark - DJIRCInfo
/*********************************************************************************/

/**
 *  This class contains the information for a remote controller.
 */
@interface DJIRCInfo : NSObject

/**
 *  Remote Controller's unique identifier.
 */
@property(nonatomic, assign) DJIRCID identifier;

/**
 *  Remote Controller's name.
 */
@property(nonatomic, strong) NSString *_Nullable name;

/**
 *  Remote Controller's password.
 */
@property(nonatomic, strong) NSString *_Nullable password;

/**
 *  Signal quality of a conneected master or slave Remote Controller.
 */
@property(nonatomic, assign) DJIRCSignalQualityOfConnectedRC signalQuality;

/**
 *  Remote Controller's control permissions.
 */
@property(nonatomic, assign) DJIRCControlPermission controlPermission;

/**
 *  Converts the Remote Controller's unique identifier from the property `identifier` to a string.
 *
 *  @return Remote Controller's identifier as a string.
 */
- (NSString *_Nullable)RCIdentifier;

@end

/*********************************************************************************/
#pragma mark - DJIRCMasterSlaveState
/*********************************************************************************/
/**
 *  State of the remote controller related to the master and slave mode.
 *  Only supported by Inspire 2.
 */
@interface DJIRCMasterSlaveState : NSObject

/**
 *  The master/slave mode of the remote controller.
 */
@property(nonatomic, readonly) DJIRemoteControllerMode mode;
/**
 *  `YES` if a the remote controller is part of a master/slave pairing.
 */
@property(nonatomic, readonly) BOOL isConnected;
/**
 *  ID of the master remote controller.
 */
@property(nonatomic, readonly) NSString *masterID;
/**
 *  ID of the slave remote controller.
 */
@property(nonatomic, readonly) NSString *slaveID;
/**
 *  Authorization code of the master remote controller that is a 6 element
 *  string of numbers.
 */
@property(nonatomic, readonly) NSString *authorizationCode;

@end


NS_ASSUME_NONNULL_END
