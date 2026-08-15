#pragma once
// MESSAGE TRITRI_TRACK PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_TRITRI_TRACK 53900


typedef struct __mavlink_tritri_track_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX epoch, microseconds UTC).*/
 uint64_t first_detected_usec; /*< [us] Time the object was first detected (UNIX epoch, microseconds UTC).*/
 uint32_t target_set_id; /*<  Associated target set identifier, if any. 0 = none.*/
 float id_confidence; /*<  Confidence of identification [0.0-1.0]. NaN if not provided.*/
 uint16_t atr_model_id; /*<  Identifier of the ATR model/version that produced atr_confidence_pct. 0 = unspecified.*/
 uint8_t track_uid[16]; /*<  Globally-unique track identifier (UUID). Stable across the whole chain.*/
 uint8_t origin_sysid; /*<  System ID of the platform that originated/owns this track.*/
 uint8_t origin_sensor; /*<  Sensor/method underlying the current identification.*/
 uint8_t id_method; /*<  Method by which identification was reached.*/
 uint8_t pid_status; /*<  Positive identification status (descriptive).*/
 uint8_t target_class; /*<  Classification (what it is).*/
 uint8_t target_force; /*<  Force affiliation.*/
 uint8_t stanag_identity; /*<  STANAG/APP-6 standard identity.*/
 uint8_t environment; /*<  STANAG/APP-6 battle dimension / environment.*/
 uint8_t atr_confidence_pct; /*< [%] ATR model confidence [0-100]. 255 = N/A.*/
 uint8_t atr_conf_tier; /*<  OPTIONAL advisory display tier. Not for automated ROE.*/
 uint8_t sidc_context; /*<  Reality vs exercise vs simulation (SIDC digit 3).*/
} mavlink_tritri_track_t;

#define MAVLINK_MSG_ID_TRITRI_TRACK_LEN 53
#define MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN 53
#define MAVLINK_MSG_ID_53900_LEN 53
#define MAVLINK_MSG_ID_53900_MIN_LEN 53

#define MAVLINK_MSG_ID_TRITRI_TRACK_CRC 229
#define MAVLINK_MSG_ID_53900_CRC 229

#define MAVLINK_MSG_TRITRI_TRACK_FIELD_TRACK_UID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRITRI_TRACK { \
    53900, \
    "TRITRI_TRACK", \
    17, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_tritri_track_t, time_usec) }, \
         { "first_detected_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_tritri_track_t, first_detected_usec) }, \
         { "track_uid", NULL, MAVLINK_TYPE_UINT8_T, 16, 26, offsetof(mavlink_tritri_track_t, track_uid) }, \
         { "target_set_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_tritri_track_t, target_set_id) }, \
         { "id_confidence", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_tritri_track_t, id_confidence) }, \
         { "atr_model_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_tritri_track_t, atr_model_id) }, \
         { "origin_sysid", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_tritri_track_t, origin_sysid) }, \
         { "origin_sensor", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_tritri_track_t, origin_sensor) }, \
         { "id_method", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_tritri_track_t, id_method) }, \
         { "pid_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_tritri_track_t, pid_status) }, \
         { "target_class", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_tritri_track_t, target_class) }, \
         { "target_force", NULL, MAVLINK_TYPE_UINT8_T, 0, 47, offsetof(mavlink_tritri_track_t, target_force) }, \
         { "stanag_identity", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_tritri_track_t, stanag_identity) }, \
         { "environment", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_tritri_track_t, environment) }, \
         { "atr_confidence_pct", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_tritri_track_t, atr_confidence_pct) }, \
         { "atr_conf_tier", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_tritri_track_t, atr_conf_tier) }, \
         { "sidc_context", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_tritri_track_t, sidc_context) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRITRI_TRACK { \
    "TRITRI_TRACK", \
    17, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_tritri_track_t, time_usec) }, \
         { "first_detected_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_tritri_track_t, first_detected_usec) }, \
         { "track_uid", NULL, MAVLINK_TYPE_UINT8_T, 16, 26, offsetof(mavlink_tritri_track_t, track_uid) }, \
         { "target_set_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_tritri_track_t, target_set_id) }, \
         { "id_confidence", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_tritri_track_t, id_confidence) }, \
         { "atr_model_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_tritri_track_t, atr_model_id) }, \
         { "origin_sysid", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_tritri_track_t, origin_sysid) }, \
         { "origin_sensor", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_tritri_track_t, origin_sensor) }, \
         { "id_method", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_tritri_track_t, id_method) }, \
         { "pid_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_tritri_track_t, pid_status) }, \
         { "target_class", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_tritri_track_t, target_class) }, \
         { "target_force", NULL, MAVLINK_TYPE_UINT8_T, 0, 47, offsetof(mavlink_tritri_track_t, target_force) }, \
         { "stanag_identity", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_tritri_track_t, stanag_identity) }, \
         { "environment", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_tritri_track_t, environment) }, \
         { "atr_confidence_pct", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_tritri_track_t, atr_confidence_pct) }, \
         { "atr_conf_tier", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_tritri_track_t, atr_conf_tier) }, \
         { "sidc_context", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_tritri_track_t, sidc_context) }, \
         } \
}
#endif

/**
 * @brief Pack a tritri_track message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param first_detected_usec [us] Time the object was first detected (UNIX epoch, microseconds UTC).
 * @param track_uid  Globally-unique track identifier (UUID). Stable across the whole chain.
 * @param target_set_id  Associated target set identifier, if any. 0 = none.
 * @param id_confidence  Confidence of identification [0.0-1.0]. NaN if not provided.
 * @param atr_model_id  Identifier of the ATR model/version that produced atr_confidence_pct. 0 = unspecified.
 * @param origin_sysid  System ID of the platform that originated/owns this track.
 * @param origin_sensor  Sensor/method underlying the current identification.
 * @param id_method  Method by which identification was reached.
 * @param pid_status  Positive identification status (descriptive).
 * @param target_class  Classification (what it is).
 * @param target_force  Force affiliation.
 * @param stanag_identity  STANAG/APP-6 standard identity.
 * @param environment  STANAG/APP-6 battle dimension / environment.
 * @param atr_confidence_pct [%] ATR model confidence [0-100]. 255 = N/A.
 * @param atr_conf_tier  OPTIONAL advisory display tier. Not for automated ROE.
 * @param sidc_context  Reality vs exercise vs simulation (SIDC digit 3).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tritri_track_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint64_t first_detected_usec, const uint8_t *track_uid, uint32_t target_set_id, float id_confidence, uint16_t atr_model_id, uint8_t origin_sysid, uint8_t origin_sensor, uint8_t id_method, uint8_t pid_status, uint8_t target_class, uint8_t target_force, uint8_t stanag_identity, uint8_t environment, uint8_t atr_confidence_pct, uint8_t atr_conf_tier, uint8_t sidc_context)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRITRI_TRACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, first_detected_usec);
    _mav_put_uint32_t(buf, 16, target_set_id);
    _mav_put_float(buf, 20, id_confidence);
    _mav_put_uint16_t(buf, 24, atr_model_id);
    _mav_put_uint8_t(buf, 42, origin_sysid);
    _mav_put_uint8_t(buf, 43, origin_sensor);
    _mav_put_uint8_t(buf, 44, id_method);
    _mav_put_uint8_t(buf, 45, pid_status);
    _mav_put_uint8_t(buf, 46, target_class);
    _mav_put_uint8_t(buf, 47, target_force);
    _mav_put_uint8_t(buf, 48, stanag_identity);
    _mav_put_uint8_t(buf, 49, environment);
    _mav_put_uint8_t(buf, 50, atr_confidence_pct);
    _mav_put_uint8_t(buf, 51, atr_conf_tier);
    _mav_put_uint8_t(buf, 52, sidc_context);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRITRI_TRACK_LEN);
#else
    mavlink_tritri_track_t packet;
    packet.time_usec = time_usec;
    packet.first_detected_usec = first_detected_usec;
    packet.target_set_id = target_set_id;
    packet.id_confidence = id_confidence;
    packet.atr_model_id = atr_model_id;
    packet.origin_sysid = origin_sysid;
    packet.origin_sensor = origin_sensor;
    packet.id_method = id_method;
    packet.pid_status = pid_status;
    packet.target_class = target_class;
    packet.target_force = target_force;
    packet.stanag_identity = stanag_identity;
    packet.environment = environment;
    packet.atr_confidence_pct = atr_confidence_pct;
    packet.atr_conf_tier = atr_conf_tier;
    packet.sidc_context = sidc_context;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRITRI_TRACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRITRI_TRACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_CRC);
}

/**
 * @brief Pack a tritri_track message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param first_detected_usec [us] Time the object was first detected (UNIX epoch, microseconds UTC).
 * @param track_uid  Globally-unique track identifier (UUID). Stable across the whole chain.
 * @param target_set_id  Associated target set identifier, if any. 0 = none.
 * @param id_confidence  Confidence of identification [0.0-1.0]. NaN if not provided.
 * @param atr_model_id  Identifier of the ATR model/version that produced atr_confidence_pct. 0 = unspecified.
 * @param origin_sysid  System ID of the platform that originated/owns this track.
 * @param origin_sensor  Sensor/method underlying the current identification.
 * @param id_method  Method by which identification was reached.
 * @param pid_status  Positive identification status (descriptive).
 * @param target_class  Classification (what it is).
 * @param target_force  Force affiliation.
 * @param stanag_identity  STANAG/APP-6 standard identity.
 * @param environment  STANAG/APP-6 battle dimension / environment.
 * @param atr_confidence_pct [%] ATR model confidence [0-100]. 255 = N/A.
 * @param atr_conf_tier  OPTIONAL advisory display tier. Not for automated ROE.
 * @param sidc_context  Reality vs exercise vs simulation (SIDC digit 3).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tritri_track_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, uint64_t first_detected_usec, const uint8_t *track_uid, uint32_t target_set_id, float id_confidence, uint16_t atr_model_id, uint8_t origin_sysid, uint8_t origin_sensor, uint8_t id_method, uint8_t pid_status, uint8_t target_class, uint8_t target_force, uint8_t stanag_identity, uint8_t environment, uint8_t atr_confidence_pct, uint8_t atr_conf_tier, uint8_t sidc_context)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRITRI_TRACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, first_detected_usec);
    _mav_put_uint32_t(buf, 16, target_set_id);
    _mav_put_float(buf, 20, id_confidence);
    _mav_put_uint16_t(buf, 24, atr_model_id);
    _mav_put_uint8_t(buf, 42, origin_sysid);
    _mav_put_uint8_t(buf, 43, origin_sensor);
    _mav_put_uint8_t(buf, 44, id_method);
    _mav_put_uint8_t(buf, 45, pid_status);
    _mav_put_uint8_t(buf, 46, target_class);
    _mav_put_uint8_t(buf, 47, target_force);
    _mav_put_uint8_t(buf, 48, stanag_identity);
    _mav_put_uint8_t(buf, 49, environment);
    _mav_put_uint8_t(buf, 50, atr_confidence_pct);
    _mav_put_uint8_t(buf, 51, atr_conf_tier);
    _mav_put_uint8_t(buf, 52, sidc_context);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRITRI_TRACK_LEN);
#else
    mavlink_tritri_track_t packet;
    packet.time_usec = time_usec;
    packet.first_detected_usec = first_detected_usec;
    packet.target_set_id = target_set_id;
    packet.id_confidence = id_confidence;
    packet.atr_model_id = atr_model_id;
    packet.origin_sysid = origin_sysid;
    packet.origin_sensor = origin_sensor;
    packet.id_method = id_method;
    packet.pid_status = pid_status;
    packet.target_class = target_class;
    packet.target_force = target_force;
    packet.stanag_identity = stanag_identity;
    packet.environment = environment;
    packet.atr_confidence_pct = atr_confidence_pct;
    packet.atr_conf_tier = atr_conf_tier;
    packet.sidc_context = sidc_context;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRITRI_TRACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRITRI_TRACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN);
#endif
}

/**
 * @brief Pack a tritri_track message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param first_detected_usec [us] Time the object was first detected (UNIX epoch, microseconds UTC).
 * @param track_uid  Globally-unique track identifier (UUID). Stable across the whole chain.
 * @param target_set_id  Associated target set identifier, if any. 0 = none.
 * @param id_confidence  Confidence of identification [0.0-1.0]. NaN if not provided.
 * @param atr_model_id  Identifier of the ATR model/version that produced atr_confidence_pct. 0 = unspecified.
 * @param origin_sysid  System ID of the platform that originated/owns this track.
 * @param origin_sensor  Sensor/method underlying the current identification.
 * @param id_method  Method by which identification was reached.
 * @param pid_status  Positive identification status (descriptive).
 * @param target_class  Classification (what it is).
 * @param target_force  Force affiliation.
 * @param stanag_identity  STANAG/APP-6 standard identity.
 * @param environment  STANAG/APP-6 battle dimension / environment.
 * @param atr_confidence_pct [%] ATR model confidence [0-100]. 255 = N/A.
 * @param atr_conf_tier  OPTIONAL advisory display tier. Not for automated ROE.
 * @param sidc_context  Reality vs exercise vs simulation (SIDC digit 3).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tritri_track_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint64_t first_detected_usec,const uint8_t *track_uid,uint32_t target_set_id,float id_confidence,uint16_t atr_model_id,uint8_t origin_sysid,uint8_t origin_sensor,uint8_t id_method,uint8_t pid_status,uint8_t target_class,uint8_t target_force,uint8_t stanag_identity,uint8_t environment,uint8_t atr_confidence_pct,uint8_t atr_conf_tier,uint8_t sidc_context)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRITRI_TRACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, first_detected_usec);
    _mav_put_uint32_t(buf, 16, target_set_id);
    _mav_put_float(buf, 20, id_confidence);
    _mav_put_uint16_t(buf, 24, atr_model_id);
    _mav_put_uint8_t(buf, 42, origin_sysid);
    _mav_put_uint8_t(buf, 43, origin_sensor);
    _mav_put_uint8_t(buf, 44, id_method);
    _mav_put_uint8_t(buf, 45, pid_status);
    _mav_put_uint8_t(buf, 46, target_class);
    _mav_put_uint8_t(buf, 47, target_force);
    _mav_put_uint8_t(buf, 48, stanag_identity);
    _mav_put_uint8_t(buf, 49, environment);
    _mav_put_uint8_t(buf, 50, atr_confidence_pct);
    _mav_put_uint8_t(buf, 51, atr_conf_tier);
    _mav_put_uint8_t(buf, 52, sidc_context);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRITRI_TRACK_LEN);
#else
    mavlink_tritri_track_t packet;
    packet.time_usec = time_usec;
    packet.first_detected_usec = first_detected_usec;
    packet.target_set_id = target_set_id;
    packet.id_confidence = id_confidence;
    packet.atr_model_id = atr_model_id;
    packet.origin_sysid = origin_sysid;
    packet.origin_sensor = origin_sensor;
    packet.id_method = id_method;
    packet.pid_status = pid_status;
    packet.target_class = target_class;
    packet.target_force = target_force;
    packet.stanag_identity = stanag_identity;
    packet.environment = environment;
    packet.atr_confidence_pct = atr_confidence_pct;
    packet.atr_conf_tier = atr_conf_tier;
    packet.sidc_context = sidc_context;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRITRI_TRACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRITRI_TRACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_CRC);
}

/**
 * @brief Encode a tritri_track struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tritri_track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tritri_track_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tritri_track_t* tritri_track)
{
    return mavlink_msg_tritri_track_pack(system_id, component_id, msg, tritri_track->time_usec, tritri_track->first_detected_usec, tritri_track->track_uid, tritri_track->target_set_id, tritri_track->id_confidence, tritri_track->atr_model_id, tritri_track->origin_sysid, tritri_track->origin_sensor, tritri_track->id_method, tritri_track->pid_status, tritri_track->target_class, tritri_track->target_force, tritri_track->stanag_identity, tritri_track->environment, tritri_track->atr_confidence_pct, tritri_track->atr_conf_tier, tritri_track->sidc_context);
}

/**
 * @brief Encode a tritri_track struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tritri_track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tritri_track_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tritri_track_t* tritri_track)
{
    return mavlink_msg_tritri_track_pack_chan(system_id, component_id, chan, msg, tritri_track->time_usec, tritri_track->first_detected_usec, tritri_track->track_uid, tritri_track->target_set_id, tritri_track->id_confidence, tritri_track->atr_model_id, tritri_track->origin_sysid, tritri_track->origin_sensor, tritri_track->id_method, tritri_track->pid_status, tritri_track->target_class, tritri_track->target_force, tritri_track->stanag_identity, tritri_track->environment, tritri_track->atr_confidence_pct, tritri_track->atr_conf_tier, tritri_track->sidc_context);
}

/**
 * @brief Encode a tritri_track struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param tritri_track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tritri_track_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_tritri_track_t* tritri_track)
{
    return mavlink_msg_tritri_track_pack_status(system_id, component_id, _status, msg,  tritri_track->time_usec, tritri_track->first_detected_usec, tritri_track->track_uid, tritri_track->target_set_id, tritri_track->id_confidence, tritri_track->atr_model_id, tritri_track->origin_sysid, tritri_track->origin_sensor, tritri_track->id_method, tritri_track->pid_status, tritri_track->target_class, tritri_track->target_force, tritri_track->stanag_identity, tritri_track->environment, tritri_track->atr_confidence_pct, tritri_track->atr_conf_tier, tritri_track->sidc_context);
}

/**
 * @brief Send a tritri_track message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param first_detected_usec [us] Time the object was first detected (UNIX epoch, microseconds UTC).
 * @param track_uid  Globally-unique track identifier (UUID). Stable across the whole chain.
 * @param target_set_id  Associated target set identifier, if any. 0 = none.
 * @param id_confidence  Confidence of identification [0.0-1.0]. NaN if not provided.
 * @param atr_model_id  Identifier of the ATR model/version that produced atr_confidence_pct. 0 = unspecified.
 * @param origin_sysid  System ID of the platform that originated/owns this track.
 * @param origin_sensor  Sensor/method underlying the current identification.
 * @param id_method  Method by which identification was reached.
 * @param pid_status  Positive identification status (descriptive).
 * @param target_class  Classification (what it is).
 * @param target_force  Force affiliation.
 * @param stanag_identity  STANAG/APP-6 standard identity.
 * @param environment  STANAG/APP-6 battle dimension / environment.
 * @param atr_confidence_pct [%] ATR model confidence [0-100]. 255 = N/A.
 * @param atr_conf_tier  OPTIONAL advisory display tier. Not for automated ROE.
 * @param sidc_context  Reality vs exercise vs simulation (SIDC digit 3).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tritri_track_send(mavlink_channel_t chan, uint64_t time_usec, uint64_t first_detected_usec, const uint8_t *track_uid, uint32_t target_set_id, float id_confidence, uint16_t atr_model_id, uint8_t origin_sysid, uint8_t origin_sensor, uint8_t id_method, uint8_t pid_status, uint8_t target_class, uint8_t target_force, uint8_t stanag_identity, uint8_t environment, uint8_t atr_confidence_pct, uint8_t atr_conf_tier, uint8_t sidc_context)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRITRI_TRACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, first_detected_usec);
    _mav_put_uint32_t(buf, 16, target_set_id);
    _mav_put_float(buf, 20, id_confidence);
    _mav_put_uint16_t(buf, 24, atr_model_id);
    _mav_put_uint8_t(buf, 42, origin_sysid);
    _mav_put_uint8_t(buf, 43, origin_sensor);
    _mav_put_uint8_t(buf, 44, id_method);
    _mav_put_uint8_t(buf, 45, pid_status);
    _mav_put_uint8_t(buf, 46, target_class);
    _mav_put_uint8_t(buf, 47, target_force);
    _mav_put_uint8_t(buf, 48, stanag_identity);
    _mav_put_uint8_t(buf, 49, environment);
    _mav_put_uint8_t(buf, 50, atr_confidence_pct);
    _mav_put_uint8_t(buf, 51, atr_conf_tier);
    _mav_put_uint8_t(buf, 52, sidc_context);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRITRI_TRACK, buf, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_CRC);
#else
    mavlink_tritri_track_t packet;
    packet.time_usec = time_usec;
    packet.first_detected_usec = first_detected_usec;
    packet.target_set_id = target_set_id;
    packet.id_confidence = id_confidence;
    packet.atr_model_id = atr_model_id;
    packet.origin_sysid = origin_sysid;
    packet.origin_sensor = origin_sensor;
    packet.id_method = id_method;
    packet.pid_status = pid_status;
    packet.target_class = target_class;
    packet.target_force = target_force;
    packet.stanag_identity = stanag_identity;
    packet.environment = environment;
    packet.atr_confidence_pct = atr_confidence_pct;
    packet.atr_conf_tier = atr_conf_tier;
    packet.sidc_context = sidc_context;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRITRI_TRACK, (const char *)&packet, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_CRC);
#endif
}

/**
 * @brief Send a tritri_track message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tritri_track_send_struct(mavlink_channel_t chan, const mavlink_tritri_track_t* tritri_track)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tritri_track_send(chan, tritri_track->time_usec, tritri_track->first_detected_usec, tritri_track->track_uid, tritri_track->target_set_id, tritri_track->id_confidence, tritri_track->atr_model_id, tritri_track->origin_sysid, tritri_track->origin_sensor, tritri_track->id_method, tritri_track->pid_status, tritri_track->target_class, tritri_track->target_force, tritri_track->stanag_identity, tritri_track->environment, tritri_track->atr_confidence_pct, tritri_track->atr_conf_tier, tritri_track->sidc_context);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRITRI_TRACK, (const char *)tritri_track, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_TRITRI_TRACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tritri_track_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint64_t first_detected_usec, const uint8_t *track_uid, uint32_t target_set_id, float id_confidence, uint16_t atr_model_id, uint8_t origin_sysid, uint8_t origin_sensor, uint8_t id_method, uint8_t pid_status, uint8_t target_class, uint8_t target_force, uint8_t stanag_identity, uint8_t environment, uint8_t atr_confidence_pct, uint8_t atr_conf_tier, uint8_t sidc_context)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, first_detected_usec);
    _mav_put_uint32_t(buf, 16, target_set_id);
    _mav_put_float(buf, 20, id_confidence);
    _mav_put_uint16_t(buf, 24, atr_model_id);
    _mav_put_uint8_t(buf, 42, origin_sysid);
    _mav_put_uint8_t(buf, 43, origin_sensor);
    _mav_put_uint8_t(buf, 44, id_method);
    _mav_put_uint8_t(buf, 45, pid_status);
    _mav_put_uint8_t(buf, 46, target_class);
    _mav_put_uint8_t(buf, 47, target_force);
    _mav_put_uint8_t(buf, 48, stanag_identity);
    _mav_put_uint8_t(buf, 49, environment);
    _mav_put_uint8_t(buf, 50, atr_confidence_pct);
    _mav_put_uint8_t(buf, 51, atr_conf_tier);
    _mav_put_uint8_t(buf, 52, sidc_context);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRITRI_TRACK, buf, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_CRC);
#else
    mavlink_tritri_track_t *packet = (mavlink_tritri_track_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->first_detected_usec = first_detected_usec;
    packet->target_set_id = target_set_id;
    packet->id_confidence = id_confidence;
    packet->atr_model_id = atr_model_id;
    packet->origin_sysid = origin_sysid;
    packet->origin_sensor = origin_sensor;
    packet->id_method = id_method;
    packet->pid_status = pid_status;
    packet->target_class = target_class;
    packet->target_force = target_force;
    packet->stanag_identity = stanag_identity;
    packet->environment = environment;
    packet->atr_confidence_pct = atr_confidence_pct;
    packet->atr_conf_tier = atr_conf_tier;
    packet->sidc_context = sidc_context;
    mav_array_memcpy(packet->track_uid, track_uid, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRITRI_TRACK, (const char *)packet, MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_LEN, MAVLINK_MSG_ID_TRITRI_TRACK_CRC);
#endif
}
#endif

#endif

// MESSAGE TRITRI_TRACK UNPACKING


/**
 * @brief Get field time_usec from tritri_track message
 *
 * @return [us] Timestamp (UNIX epoch, microseconds UTC).
 */
static inline uint64_t mavlink_msg_tritri_track_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field first_detected_usec from tritri_track message
 *
 * @return [us] Time the object was first detected (UNIX epoch, microseconds UTC).
 */
static inline uint64_t mavlink_msg_tritri_track_get_first_detected_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field track_uid from tritri_track message
 *
 * @return  Globally-unique track identifier (UUID). Stable across the whole chain.
 */
static inline uint16_t mavlink_msg_tritri_track_get_track_uid(const mavlink_message_t* msg, uint8_t *track_uid)
{
    return _MAV_RETURN_uint8_t_array(msg, track_uid, 16,  26);
}

/**
 * @brief Get field target_set_id from tritri_track message
 *
 * @return  Associated target set identifier, if any. 0 = none.
 */
static inline uint32_t mavlink_msg_tritri_track_get_target_set_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field id_confidence from tritri_track message
 *
 * @return  Confidence of identification [0.0-1.0]. NaN if not provided.
 */
static inline float mavlink_msg_tritri_track_get_id_confidence(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field atr_model_id from tritri_track message
 *
 * @return  Identifier of the ATR model/version that produced atr_confidence_pct. 0 = unspecified.
 */
static inline uint16_t mavlink_msg_tritri_track_get_atr_model_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field origin_sysid from tritri_track message
 *
 * @return  System ID of the platform that originated/owns this track.
 */
static inline uint8_t mavlink_msg_tritri_track_get_origin_sysid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field origin_sensor from tritri_track message
 *
 * @return  Sensor/method underlying the current identification.
 */
static inline uint8_t mavlink_msg_tritri_track_get_origin_sensor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Get field id_method from tritri_track message
 *
 * @return  Method by which identification was reached.
 */
static inline uint8_t mavlink_msg_tritri_track_get_id_method(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field pid_status from tritri_track message
 *
 * @return  Positive identification status (descriptive).
 */
static inline uint8_t mavlink_msg_tritri_track_get_pid_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  45);
}

/**
 * @brief Get field target_class from tritri_track message
 *
 * @return  Classification (what it is).
 */
static inline uint8_t mavlink_msg_tritri_track_get_target_class(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  46);
}

/**
 * @brief Get field target_force from tritri_track message
 *
 * @return  Force affiliation.
 */
static inline uint8_t mavlink_msg_tritri_track_get_target_force(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  47);
}

/**
 * @brief Get field stanag_identity from tritri_track message
 *
 * @return  STANAG/APP-6 standard identity.
 */
static inline uint8_t mavlink_msg_tritri_track_get_stanag_identity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Get field environment from tritri_track message
 *
 * @return  STANAG/APP-6 battle dimension / environment.
 */
static inline uint8_t mavlink_msg_tritri_track_get_environment(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  49);
}

/**
 * @brief Get field atr_confidence_pct from tritri_track message
 *
 * @return [%] ATR model confidence [0-100]. 255 = N/A.
 */
static inline uint8_t mavlink_msg_tritri_track_get_atr_confidence_pct(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  50);
}

/**
 * @brief Get field atr_conf_tier from tritri_track message
 *
 * @return  OPTIONAL advisory display tier. Not for automated ROE.
 */
static inline uint8_t mavlink_msg_tritri_track_get_atr_conf_tier(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  51);
}

/**
 * @brief Get field sidc_context from tritri_track message
 *
 * @return  Reality vs exercise vs simulation (SIDC digit 3).
 */
static inline uint8_t mavlink_msg_tritri_track_get_sidc_context(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Decode a tritri_track message into a struct
 *
 * @param msg The message to decode
 * @param tritri_track C-struct to decode the message contents into
 */
static inline void mavlink_msg_tritri_track_decode(const mavlink_message_t* msg, mavlink_tritri_track_t* tritri_track)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tritri_track->time_usec = mavlink_msg_tritri_track_get_time_usec(msg);
    tritri_track->first_detected_usec = mavlink_msg_tritri_track_get_first_detected_usec(msg);
    tritri_track->target_set_id = mavlink_msg_tritri_track_get_target_set_id(msg);
    tritri_track->id_confidence = mavlink_msg_tritri_track_get_id_confidence(msg);
    tritri_track->atr_model_id = mavlink_msg_tritri_track_get_atr_model_id(msg);
    mavlink_msg_tritri_track_get_track_uid(msg, tritri_track->track_uid);
    tritri_track->origin_sysid = mavlink_msg_tritri_track_get_origin_sysid(msg);
    tritri_track->origin_sensor = mavlink_msg_tritri_track_get_origin_sensor(msg);
    tritri_track->id_method = mavlink_msg_tritri_track_get_id_method(msg);
    tritri_track->pid_status = mavlink_msg_tritri_track_get_pid_status(msg);
    tritri_track->target_class = mavlink_msg_tritri_track_get_target_class(msg);
    tritri_track->target_force = mavlink_msg_tritri_track_get_target_force(msg);
    tritri_track->stanag_identity = mavlink_msg_tritri_track_get_stanag_identity(msg);
    tritri_track->environment = mavlink_msg_tritri_track_get_environment(msg);
    tritri_track->atr_confidence_pct = mavlink_msg_tritri_track_get_atr_confidence_pct(msg);
    tritri_track->atr_conf_tier = mavlink_msg_tritri_track_get_atr_conf_tier(msg);
    tritri_track->sidc_context = mavlink_msg_tritri_track_get_sidc_context(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TRITRI_TRACK_LEN? msg->len : MAVLINK_MSG_ID_TRITRI_TRACK_LEN;
        memset(tritri_track, 0, MAVLINK_MSG_ID_TRITRI_TRACK_LEN);
    memcpy(tritri_track, _MAV_PAYLOAD(msg), len);
#endif
}
