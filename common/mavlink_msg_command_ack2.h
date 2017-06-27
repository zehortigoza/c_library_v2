#pragma once
// MESSAGE COMMAND_ACK2 PACKING

#define MAVLINK_MSG_ID_COMMAND_ACK2 78

MAVPACKED(
typedef struct __mavlink_command_ack2_t {
 int32_t result_param2; /*< Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.*/
 uint16_t command; /*< Command ID, as defined by MAV_CMD enum.*/
 uint16_t result_param1; /*< It can be a enum with the reason why command was denied or the progress percentage when result is MAV_RESULT_IN_PROGRESS.*/
 uint8_t target_system; /*< System which requested the command to be executed*/
 uint8_t target_component; /*< Component which requested the command to be executed*/
 uint8_t result; /*< See MAV_RESULT enum*/
}) mavlink_command_ack2_t;

#define MAVLINK_MSG_ID_COMMAND_ACK2_LEN 11
#define MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN 11
#define MAVLINK_MSG_ID_78_LEN 11
#define MAVLINK_MSG_ID_78_MIN_LEN 11

#define MAVLINK_MSG_ID_COMMAND_ACK2_CRC 97
#define MAVLINK_MSG_ID_78_CRC 97



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMMAND_ACK2 { \
    78, \
    "COMMAND_ACK2", \
    6, \
    {  { "result_param2", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_command_ack2_t, result_param2) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_command_ack2_t, command) }, \
         { "result_param1", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_command_ack2_t, result_param1) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_command_ack2_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_command_ack2_t, target_component) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_command_ack2_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMMAND_ACK2 { \
    "COMMAND_ACK2", \
    6, \
    {  { "result_param2", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_command_ack2_t, result_param2) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_command_ack2_t, command) }, \
         { "result_param1", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_command_ack2_t, result_param1) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_command_ack2_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_command_ack2_t, target_component) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_command_ack2_t, result) }, \
         } \
}
#endif

/**
 * @brief Pack a command_ack2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System which requested the command to be executed
 * @param target_component Component which requested the command to be executed
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param result See MAV_RESULT enum
 * @param result_param1 It can be a enum with the reason why command was denied or the progress percentage when result is MAV_RESULT_IN_PROGRESS.
 * @param result_param2 Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_ack2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t command, uint8_t result, uint16_t result_param1, int32_t result_param2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_ACK2_LEN];
    _mav_put_int32_t(buf, 0, result_param2);
    _mav_put_uint16_t(buf, 4, command);
    _mav_put_uint16_t(buf, 6, result_param1);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
#else
    mavlink_command_ack2_t packet;
    packet.result_param2 = result_param2;
    packet.command = command;
    packet.result_param1 = result_param1;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_ACK2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
}

/**
 * @brief Pack a command_ack2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System which requested the command to be executed
 * @param target_component Component which requested the command to be executed
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param result See MAV_RESULT enum
 * @param result_param1 It can be a enum with the reason why command was denied or the progress percentage when result is MAV_RESULT_IN_PROGRESS.
 * @param result_param2 Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_ack2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t command,uint8_t result,uint16_t result_param1,int32_t result_param2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_ACK2_LEN];
    _mav_put_int32_t(buf, 0, result_param2);
    _mav_put_uint16_t(buf, 4, command);
    _mav_put_uint16_t(buf, 6, result_param1);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
#else
    mavlink_command_ack2_t packet;
    packet.result_param2 = result_param2;
    packet.command = command;
    packet.result_param1 = result_param1;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_ACK2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
}

/**
 * @brief Encode a command_ack2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command_ack2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_ack2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_ack2_t* command_ack2)
{
    return mavlink_msg_command_ack2_pack(system_id, component_id, msg, command_ack2->target_system, command_ack2->target_component, command_ack2->command, command_ack2->result, command_ack2->result_param1, command_ack2->result_param2);
}

/**
 * @brief Encode a command_ack2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command_ack2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_ack2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_command_ack2_t* command_ack2)
{
    return mavlink_msg_command_ack2_pack_chan(system_id, component_id, chan, msg, command_ack2->target_system, command_ack2->target_component, command_ack2->command, command_ack2->result, command_ack2->result_param1, command_ack2->result_param2);
}

/**
 * @brief Send a command_ack2 message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System which requested the command to be executed
 * @param target_component Component which requested the command to be executed
 * @param command Command ID, as defined by MAV_CMD enum.
 * @param result See MAV_RESULT enum
 * @param result_param1 It can be a enum with the reason why command was denied or the progress percentage when result is MAV_RESULT_IN_PROGRESS.
 * @param result_param2 Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_command_ack2_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t command, uint8_t result, uint16_t result_param1, int32_t result_param2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_ACK2_LEN];
    _mav_put_int32_t(buf, 0, result_param2);
    _mav_put_uint16_t(buf, 4, command);
    _mav_put_uint16_t(buf, 6, result_param1);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, buf, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#else
    mavlink_command_ack2_t packet;
    packet.result_param2 = result_param2;
    packet.command = command;
    packet.result_param1 = result_param1;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, (const char *)&packet, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#endif
}

/**
 * @brief Send a command_ack2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_command_ack2_send_struct(mavlink_channel_t chan, const mavlink_command_ack2_t* command_ack2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_command_ack2_send(chan, command_ack2->target_system, command_ack2->target_component, command_ack2->command, command_ack2->result, command_ack2->result_param1, command_ack2->result_param2);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, (const char *)command_ack2, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMMAND_ACK2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_command_ack2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint16_t command, uint8_t result, uint16_t result_param1, int32_t result_param2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, result_param2);
    _mav_put_uint16_t(buf, 4, command);
    _mav_put_uint16_t(buf, 6, result_param1);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, buf, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#else
    mavlink_command_ack2_t *packet = (mavlink_command_ack2_t *)msgbuf;
    packet->result_param2 = result_param2;
    packet->command = command;
    packet->result_param1 = result_param1;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, (const char *)packet, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#endif
}
#endif

#endif

// MESSAGE COMMAND_ACK2 UNPACKING


/**
 * @brief Get field target_system from command_ack2 message
 *
 * @return System which requested the command to be executed
 */
static inline uint8_t mavlink_msg_command_ack2_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field target_component from command_ack2 message
 *
 * @return Component which requested the command to be executed
 */
static inline uint8_t mavlink_msg_command_ack2_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field command from command_ack2 message
 *
 * @return Command ID, as defined by MAV_CMD enum.
 */
static inline uint16_t mavlink_msg_command_ack2_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field result from command_ack2 message
 *
 * @return See MAV_RESULT enum
 */
static inline uint8_t mavlink_msg_command_ack2_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field result_param1 from command_ack2 message
 *
 * @return It can be a enum with the reason why command was denied or the progress percentage when result is MAV_RESULT_IN_PROGRESS.
 */
static inline uint16_t mavlink_msg_command_ack2_get_result_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field result_param2 from command_ack2 message
 *
 * @return Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.
 */
static inline int32_t mavlink_msg_command_ack2_get_result_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a command_ack2 message into a struct
 *
 * @param msg The message to decode
 * @param command_ack2 C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_ack2_decode(const mavlink_message_t* msg, mavlink_command_ack2_t* command_ack2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    command_ack2->result_param2 = mavlink_msg_command_ack2_get_result_param2(msg);
    command_ack2->command = mavlink_msg_command_ack2_get_command(msg);
    command_ack2->result_param1 = mavlink_msg_command_ack2_get_result_param1(msg);
    command_ack2->target_system = mavlink_msg_command_ack2_get_target_system(msg);
    command_ack2->target_component = mavlink_msg_command_ack2_get_target_component(msg);
    command_ack2->result = mavlink_msg_command_ack2_get_result(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMMAND_ACK2_LEN? msg->len : MAVLINK_MSG_ID_COMMAND_ACK2_LEN;
        memset(command_ack2, 0, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
    memcpy(command_ack2, _MAV_PAYLOAD(msg), len);
#endif
}
