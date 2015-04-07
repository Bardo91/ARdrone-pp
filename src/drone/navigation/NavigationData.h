///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: library
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-07
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	This document defines the basic ARdrone navdata structure.

struct ARDRONE_NAVDATA {
	struct eulerMat {
		float m11, m12, m13;
		float m21, m22, m23;
		float m31, m32, m33;
	};

	union position {
		float v[3];
		struct {
			float x;
			float y;
			float z;
		};
	};

	// 2x1 vector
	union vector21_t {
		float v[2];
		struct {
			float x;
			float y;
		};
	};

	// Velocities
	struct speed {
		float x;
		float y;
		float z;
	};

	// Screen point
	struct screen_point_t {
		int x;
		int y;
	};

	// Header
	unsigned int header;
	unsigned int ardrone_state;
	unsigned int sequence;
	unsigned int vision_defined;

	// Demo
	struct NAVDATA_DEMO {
		unsigned short	tag;
		unsigned short	size;
		unsigned int	ctrl_state;
		unsigned int	vbat_flying_percentage;
		float			theta;
		float			phi;
		float			psi;
		int				altitude;
		float			vx;
		float			vy;
		float			vz;
		unsigned int	num_frames;                // Don't use
		eulerMat		detection_camera_rot;      // Don't use
		position		detection_camera_trans;    // Don't use
		unsigned int	detection_tag_index;       // Don't use
		unsigned int	detection_camera_type;     // Don't use
		eulerMat		drone_camera_rot;          // Don't use
		position		drone_camera_trans;        // Don't use
	} demo;

	// Timestamp
	struct NAVDATA_TIME {
		unsigned short tag;
		unsigned short size;
		unsigned int   time;
	} time;

	// Raw measurements
	struct NAVDATA_RAW_MEASURES {
		unsigned short tag;
		unsigned short size;
		unsigned short raw_accs[3];         // filtered accelerometers
		short          raw_gyros[3];        // filtered gyrometers
		short          raw_gyros_110[2];    // gyrometers  x/y 110 deg/s
		unsigned int   vbat_raw;            // battery voltage raw (mV)
		unsigned short us_debut_echo;
		unsigned short us_fin_echo;
		unsigned short us_association_echo;
		unsigned short us_distance_echo;
		unsigned short us_courbe_temps;
		unsigned short us_courbe_valeur;
		unsigned short us_courbe_ref;
		unsigned short flag_echo_ini;
		//unsigned short frame_number;
		unsigned short nb_echo;
		unsigned int   sum_echo;
		int            alt_temp_raw;
		short          gradient;
	} raw_measures;

	// Physical measurements
	struct NAVDATA_PHYS_MEASURES {
		unsigned short tag;
		unsigned short size;
		float          accs_temp;
		unsigned short gyro_temp;
		float          phys_accs[3];
		float          phys_gyros[3];
		unsigned int   alim3V3;         // 3.3 volt alim       [LSB]
		unsigned int   vrefEpson;       // ref volt Epson gyro [LSB]
		unsigned int   vrefIDG;         // ref volt IDG gyro   [LSB]
	} phys_measures;

	// Gyros offsets
	struct NAVDATA_GYROS_OFFSETS {
		unsigned short tag;
		unsigned short size;
		float          offset_g[3];
	} gyros_offsets;

	// Euler angles
	struct NAVDATA_EULER_ANGLES {
		unsigned short tag;
		unsigned short size;
		float          theta_a;
		float          phi_a;
	} euler_angles;

	// References
	struct NAVDATA_REFERENCES {
		unsigned short tag;
		unsigned short size;
		int            ref_theta;
		int            ref_phi;
		int            ref_theta_I;
		int            ref_phi_I;
		int            ref_pitch;
		int            ref_roll;
		int            ref_yaw;
		int            ref_psi;
		float          vx_ref;
		float          vy_ref;
		float          theta_mod;
		float          phi_mod;
		float          k_v_x;
		float          k_v_y;
		unsigned int   k_mode;
		float          ui_time;
		float          ui_theta;
		float          ui_phi;
		float          ui_psi;
		float          ui_psi_accuracy;
		int            ui_seq;
	} references;

	// Trims
	struct NAVDATA_TRIMS {
		unsigned short tag;
		unsigned short size;
		float          angular_rates_trim_r;
		float          euler_angles_trim_theta;
		float          euler_angles_trim_phi;
	} trims;

	// RC references
	struct NAVDATA_RC_REFERENCES {
		unsigned short tag;
		unsigned short size;
		int            rc_ref_pitch;
		int            rc_ref_roll;
		int            rc_ref_yaw;
		int            rc_ref_gaz;
		int            rc_ref_ag;
	} rc_references;

	// PWM
	struct NAVDATA_PWM {
		unsigned short tag;
		unsigned short size;
		unsigned char  motor1;
		unsigned char  motor2;
		unsigned char  motor3;
		unsigned char  motor4;
		unsigned char  sat_motor1;
		unsigned char  sat_motor2;
		unsigned char  sat_motor3;
		unsigned char  sat_motor4;
		float          gaz_feed_forward;
		float          gaz_altitude;
		float          altitude_integral;
		float          vz_ref;
		int            u_pitch;
		int            u_roll;
		int            u_yaw;
		float          yaw_u_I;
		int            u_pitch_planif;
		int            u_roll_planif;
		int            u_yaw_planif;
		float          u_gaz_planif;
		unsigned short current_motor1;
		unsigned short current_motor2;
		unsigned short current_motor3;
		unsigned short current_motor4;
		float          altitude_prop;
		float          altitude_der;
	} pwm;

	// Altitude
	struct NAVDATA_ALTITUDE {
		unsigned short tag;
		unsigned short size;
		int            altitude_vision;
		float          altitude_vz;
		int            altitude_ref;
		int            altitude_raw;
		float          obs_accZ;
		float          obs_alt;
		position     obs_x;
		unsigned int   obs_state;
		vector21_t     est_vb;
		unsigned int   est_state;
	} altitude;

	// Vision (raw)
	struct NAVDATA_VISION_RAW {
		unsigned short tag;
		unsigned short size;
		float          vision_tx_raw;
		float          vision_ty_raw;
		float          vision_tz_raw;
	} vision_raw;

	// Vision (offset?)
	struct NAVDATA_VISION_OF {
		unsigned short tag;
		unsigned short size;
		float          of_dx[5];
		float          of_dy[5];
	} vision_of;

	// Vision
	struct NAVDATA_VISION {
		unsigned short tag;
		unsigned short size;
		unsigned int   vision_state;
		int            vision_misc;
		float          vision_phi_trim;
		float          vision_phi_ref_prop;
		float          vision_theta_trim;
		float          vision_theta_ref_prop;
		int            new_raw_picture;
		float          theta_capture;
		float          phi_capture;
		float          psi_capture;
		int            altitude_capture;
		unsigned int   time_capture;    // time in TSECDEC format (see config.h)
		speed   body_v;
		float          delta_phi;
		float          delta_theta;
		float          delta_psi;
		unsigned int   gold_defined;
		unsigned int   gold_reset;
		float          gold_x;
		float          gold_y;
	} vision;

	// Vision performances
	struct NAVDATA_VISION_PERF {
		unsigned short tag;
		unsigned short size;
		float          time_szo;
		float          time_corners;
		float          time_compute;
		float          time_tracking;
		float          time_trans;
		float          time_update;
		float          time_custom[20];
	} vision_perf;

	// Trackers
	struct NAVDATA_TRACKERS_SEND {
		unsigned short tag;
		unsigned short size;
		int            locked[30];
		screen_point_t point[30];
	} trackers_send;

	// Vision detection
	struct NAVDATA_VISION_DETECT {
		unsigned short	tag;
		unsigned short	size;
		unsigned int	nb_detected;
		unsigned int	type[4];
		unsigned int	xc[4];
		unsigned int	yc[4];
		unsigned int	width[4];
		unsigned int	height[4];
		unsigned int	dist[4];
		float			orientation_angle[4];
		eulerMat		rotation[4];
		position		translation[4];
		unsigned int	camera_source[4];
	} vision_detect;

	// Watchdog
	struct NAVDATA_WATCHDOG {
		unsigned short tag;
		unsigned short size;
		int            watchdog;
	} watchdog;

	// ADC data
	struct NAVDATA_ADC_DATA_FRAME {
		unsigned short tag;
		unsigned short size;
		unsigned int   version;
		unsigned char  data_frame[32];
	} adc_data_frame;

	// Video stream
	struct NAVDATA_VIDEO_STREAM {
		unsigned short tag;
		unsigned short size;
		unsigned char  quant;               // quantizer reference used to encode frame [1:31]
		unsigned int   frame_size;          // frame size (bytes)
		unsigned int   frame_number;        // frame index
		unsigned int   atcmd_ref_seq;       // atmcd ref sequence number
		unsigned int   atcmd_mean_ref_gap;  // mean time between two consecutive atcmd_ref (ms)
		float          atcmd_var_ref_gap;
		unsigned int   atcmd_ref_quality;   // estimator of atcmd link quality

		// drone2
		unsigned int   out_bitrate;         // measured out throughput from the video tcp socket
		unsigned int   desired_bitrate;     // last frame size generated by the video encoder
		int            data1;
		int            data2;
		int            data3;
		int            data4;
		int            data5;
		unsigned int   tcp_queue_level;
		unsigned int   fifo_queue_level;
	} video_stream;

	// Games
	struct NAVDATA_GAMES {
		unsigned short tag;
		unsigned short size;
		unsigned int   double_tap_counter;
		unsigned int   finish_line_counter;
	} games;

	// Preassure (raw)
	struct NAVDATA_PRESSURE_RAW {
		unsigned short tag;
		unsigned short size;
		unsigned int   up;
		unsigned short ut;
		unsigned int   temperature_meas;
		unsigned int   pression_meas;
	} pressure_raw;

	// Magneto
	struct NAVDATA_MAGNETO {
		unsigned short	tag;
		unsigned short	size;
		short			mx;
		short			my;
		short			mz;
		position		magneto_raw;             // magneto in the body frame, in mG
		position		magneto_rectified;
		position		magneto_offset;
		float			heading_unwrapped;
		float			heading_gyro_unwrapped;
		float			heading_fusion_unwrapped;
		char			magneto_calibration_ok;
		unsigned int	magneto_state;
		float			magneto_radius;
		float			error_mean;
		float			error_var;
		float			tmp1, tmp2;              // dummy ?
	} magneto;

	// Wind
	struct NAVDATA_WIND {
		unsigned short tag;
		unsigned short size;
		float          wind_speed;              // estimated wind speed [m/s]
		float          wind_angle;              // estimated wind direction in North-East frame [rad] e.g. if wind_angle is pi/4, wind is from South-West to North-East
		float          wind_compensation_theta;
		float          wind_compensation_phi;
		float          state_x1;
		float          state_x2;
		float          state_x3;
		float          state_x4;
		float          state_x5;
		float          state_x6;
		float          magneto_debug1;
		float          magneto_debug2;
		float          magneto_debug3;
	} wind;

	// Kalman filter
	struct NAVDATA_KALMAN_PRESSURE {
		unsigned short tag;
		unsigned short size;
		float          offset_pressure;
		float          est_z;
		float          est_zdot;
		float          est_bias_PWM;
		float          est_biais_pression;
		float          offset_US;
		float          prediction_US;
		float          cov_alt;
		float          cov_PWM;
		float          cov_vitesse;
		bool           bool_effet_sol;
		float          somme_inno;
		bool           flag_rejet_US;
		float          u_multisinus;
		float          gaz_altitude;
		bool           flag_multisinus;
		bool           flag_multisinus_debut;
	} kalman_pressure;

	// HD video stream
	struct NAVDATA_HDVIDEO_STREAM {
		unsigned short tag;
		unsigned short size;
		unsigned int   hdvideo_state;
		unsigned int   storage_fifo_nb_packets;
		unsigned int   storage_fifo_size;
		unsigned int   usbkey_size;           // USB key in kbytes - 0 if no key present
		unsigned int   usbkey_freespace;      // USB key free space in kbytes - 0 if no key present
		unsigned int   frame_number;          // 'frame_number' PaVE field of the frame starting to be encoded for the HD stream
		unsigned int   usbkey_remaining_time; // time in seconds
	} hdvideo_stream;

	// WiFi
	struct NAVDATA_WIFI {
		unsigned short tag;
		unsigned short size;
		unsigned int   link_quality;
	} wifi;

	// Zimmu 3000
	struct NAVDATA_ZIMMU_3000 {
		unsigned short tag;
		unsigned short size;
		int            vzimmuLSB;
		float          vzfind;
	} zimmu_3000;

	// GPS (for AR.Drone 2.4.1, or later)
	// From https://github.com/paparazzi/paparazzi/blob/master/sw/airborne/boards/ardrone/at_com.h
	struct NAVDATA_GPS {
		unsigned short tag;                  /*!< Navdata block ('option') identifier */
		unsigned short size;                 /*!< set this to the size of this structure */
		double         lat;                  /*!< Latitude */
		double         lon;                  /*!< Longitude */
		double         elevation;            /*!< Elevation */
		double         hdop;                 /*!< hdop */
		int            data_available;       /*!< When there is data available */
		unsigned char  unk_0[8];
		double         lat0;                 /*!< Latitude ??? */
		double         lon0;                 /*!< Longitude ??? */
		double         lat_fuse;             /*!< Latitude fused */
		double         lon_fuse;             /*!< Longitude fused */
		unsigned int   gps_state;            /*!< State of the GPS, still need to figure out */
		unsigned char  unk_1[40];
		double         vdop;                 /*!< vdop */
		double         pdop;                 /*!< pdop */
		float          speed;                /*!< speed */
		unsigned int   last_frame_timestamp; /*!< Timestamp from the last frame */
		float          degree;               /*!< Degree */
		float          degree_mag;           /*!< Degree of the magnetic */
		unsigned char  unk_2[16];
		struct {
			unsigned char sat;
			unsigned char cn0;
		} channels[12];
		int             gps_plugged;         /*!< When the gps is plugged */
		unsigned char   unk_3[108];
		double          gps_time;            /*!< The gps time of week */
		unsigned short  week;                /*!< The gps week */
		unsigned char   gps_fix;             /*!< The gps fix */
		unsigned char   num_sattelites;      /*!< Number of sattelites */
		unsigned char   unk_4[24];
		double          ned_vel_c0;          /*!< NED velocity */
		double          ned_vel_c1;          /*!< NED velocity */
		double          ned_vel_c2;          /*!< NED velocity */
		double          pos_accur_c0;        /*!< Position accuracy */
		double          pos_accur_c1;        /*!< Position accuracy */
		double          pos_accur_c2;        /*!< Position accuracy */
		float           speed_acur;          /*!< Speed accuracy */
		float           time_acur;           /*!< Time accuracy */
		unsigned char   unk_5[72];
		float           temprature;
		float           pressure;
	} gps;

	// Check sum
	struct NAVDATA_CKS {
		unsigned short tag;
		unsigned short size;
		unsigned int   cks;
	} cks;
};