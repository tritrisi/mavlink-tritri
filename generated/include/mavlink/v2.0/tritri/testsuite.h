/** @file
 *    @brief MAVLink comm protocol testsuite generated from tritri.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef TRITRI_TESTSUITE_H
#define TRITRI_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_military(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_tritri(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_military(system_id, component_id, last_msg);
    mavlink_test_tritri(system_id, component_id, last_msg);
}
#endif

#include "../military/testsuite.h"


static void mavlink_test_tritri_track(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TRITRI_TRACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tritri_track_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,963498296,157.0,18483,{ 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226 },3,70,137,204,15,82,149,216,27,94,161
    };
    mavlink_tritri_track_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.first_detected_usec = packet_in.first_detected_usec;
        packet1.target_set_id = packet_in.target_set_id;
        packet1.id_confidence = packet_in.id_confidence;
        packet1.atr_model_id = packet_in.atr_model_id;
        packet1.origin_sysid = packet_in.origin_sysid;
        packet1.origin_sensor = packet_in.origin_sensor;
        packet1.id_method = packet_in.id_method;
        packet1.pid_status = packet_in.pid_status;
        packet1.target_class = packet_in.target_class;
        packet1.target_force = packet_in.target_force;
        packet1.stanag_identity = packet_in.stanag_identity;
        packet1.environment = packet_in.environment;
        packet1.atr_confidence_pct = packet_in.atr_confidence_pct;
        packet1.atr_conf_tier = packet_in.atr_conf_tier;
        packet1.sidc_context = packet_in.sidc_context;
        
        mav_array_memcpy(packet1.track_uid, packet_in.track_uid, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TRITRI_TRACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tritri_track_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tritri_track_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tritri_track_pack(system_id, component_id, &msg , packet1.time_usec , packet1.first_detected_usec , packet1.track_uid , packet1.target_set_id , packet1.id_confidence , packet1.atr_model_id , packet1.origin_sysid , packet1.origin_sensor , packet1.id_method , packet1.pid_status , packet1.target_class , packet1.target_force , packet1.stanag_identity , packet1.environment , packet1.atr_confidence_pct , packet1.atr_conf_tier , packet1.sidc_context );
    mavlink_msg_tritri_track_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tritri_track_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.first_detected_usec , packet1.track_uid , packet1.target_set_id , packet1.id_confidence , packet1.atr_model_id , packet1.origin_sysid , packet1.origin_sensor , packet1.id_method , packet1.pid_status , packet1.target_class , packet1.target_force , packet1.stanag_identity , packet1.environment , packet1.atr_confidence_pct , packet1.atr_conf_tier , packet1.sidc_context );
    mavlink_msg_tritri_track_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tritri_track_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tritri_track_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.first_detected_usec , packet1.track_uid , packet1.target_set_id , packet1.id_confidence , packet1.atr_model_id , packet1.origin_sysid , packet1.origin_sensor , packet1.id_method , packet1.pid_status , packet1.target_class , packet1.target_force , packet1.stanag_identity , packet1.environment , packet1.atr_confidence_pct , packet1.atr_conf_tier , packet1.sidc_context );
    mavlink_msg_tritri_track_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TRITRI_TRACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TRITRI_TRACK) != NULL);
#endif
}

static void mavlink_test_tritri_target(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TRITRI_TARGET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tritri_target_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,963498296,963498504,963498712,963498920,963499128,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,493.0,521.0,21187,{ 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126 },"QRSTUVWXYZABCDE",207,18,85,152,219,30
    };
    mavlink_tritri_target_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.target_time_usec = packet_in.target_time_usec;
        packet1.target_id = packet_in.target_id;
        packet1.target_set_id = packet_in.target_set_id;
        packet1.flags = packet_in.flags;
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        packet1.vx = packet_in.vx;
        packet1.vy = packet_in.vy;
        packet1.vz = packet_in.vz;
        packet1.cov_pos_x = packet_in.cov_pos_x;
        packet1.cov_pos_y = packet_in.cov_pos_y;
        packet1.cov_pos_z = packet_in.cov_pos_z;
        packet1.cov_vel_x = packet_in.cov_vel_x;
        packet1.cov_vel_y = packet_in.cov_vel_y;
        packet1.cov_vel_z = packet_in.cov_vel_z;
        packet1.confidence = packet_in.confidence;
        packet1.target_class = packet_in.target_class;
        packet1.target_domain = packet_in.target_domain;
        packet1.target_force = packet_in.target_force;
        packet1.sensor_type = packet_in.sensor_type;
        packet1.tle_category = packet_in.tle_category;
        packet1.restricted_target_flags = packet_in.restricted_target_flags;
        
        mav_array_memcpy(packet1.track_uid, packet_in.track_uid, sizeof(uint8_t)*16);
        mav_array_memcpy(packet1.target_name, packet_in.target_name, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TRITRI_TARGET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TRITRI_TARGET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tritri_target_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tritri_target_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tritri_target_pack(system_id, component_id, &msg , packet1.time_usec , packet1.target_time_usec , packet1.track_uid , packet1.target_name , packet1.target_id , packet1.target_set_id , packet1.flags , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.cov_pos_x , packet1.cov_pos_y , packet1.cov_pos_z , packet1.cov_vel_x , packet1.cov_vel_y , packet1.cov_vel_z , packet1.confidence , packet1.target_class , packet1.target_domain , packet1.target_force , packet1.sensor_type , packet1.tle_category , packet1.restricted_target_flags );
    mavlink_msg_tritri_target_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tritri_target_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.target_time_usec , packet1.track_uid , packet1.target_name , packet1.target_id , packet1.target_set_id , packet1.flags , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.cov_pos_x , packet1.cov_pos_y , packet1.cov_pos_z , packet1.cov_vel_x , packet1.cov_vel_y , packet1.cov_vel_z , packet1.confidence , packet1.target_class , packet1.target_domain , packet1.target_force , packet1.sensor_type , packet1.tle_category , packet1.restricted_target_flags );
    mavlink_msg_tritri_target_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tritri_target_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tritri_target_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.target_time_usec , packet1.track_uid , packet1.target_name , packet1.target_id , packet1.target_set_id , packet1.flags , packet1.lat , packet1.lon , packet1.alt , packet1.vx , packet1.vy , packet1.vz , packet1.cov_pos_x , packet1.cov_pos_y , packet1.cov_pos_z , packet1.cov_vel_x , packet1.cov_vel_y , packet1.cov_vel_z , packet1.confidence , packet1.target_class , packet1.target_domain , packet1.target_force , packet1.sensor_type , packet1.tle_category , packet1.restricted_target_flags );
    mavlink_msg_tritri_target_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TRITRI_TARGET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TRITRI_TARGET) != NULL);
#endif
}

static void mavlink_test_tritri(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_tritri_track(system_id, component_id, last_msg);
    mavlink_test_tritri_target(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TRITRI_TESTSUITE_H
