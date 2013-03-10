/* ISAKMP constants.
   Copyright (C) 2002  Geoffrey Keating

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   $Id: isakmp.h 460 2011-08-22 14:19:18Z Antonio Borneo $
*/

#ifndef __ISAKMP_H__
#define __ISAKMP_H__

/* Flag bits for header.  */
#define ISAKMP_FLAG_E	0x1
#define ISAKMP_FLAG_C	0x2
#define ISAKMP_FLAG_A	0x4

/* Payload types */
enum isakmp_payload_enum {
	ISAKMP_PAYLOAD_NONE = 0,	/* RFC 2408 */
	ISAKMP_PAYLOAD_SA,		/* RFC 2408, Security Association	*/
	ISAKMP_PAYLOAD_P,		/* RFC 2408, Proposal			*/
	ISAKMP_PAYLOAD_T,		/* RFC 2408, Transform			*/
	ISAKMP_PAYLOAD_KE,		/* RFC 2408, Key Exchange		*/
	ISAKMP_PAYLOAD_ID,		/* RFC 2408, Identification		*/
	ISAKMP_PAYLOAD_CERT,		/* RFC 2408, Certificate		*/
	ISAKMP_PAYLOAD_CR,		/* RFC 2408, Certificate Request	*/
	ISAKMP_PAYLOAD_HASH,		/* RFC 2408, Hash			*/
	ISAKMP_PAYLOAD_SIG,		/* RFC 2408, Signature			*/
	ISAKMP_PAYLOAD_NONCE,		/* RFC 2408, Nonce			*/
	ISAKMP_PAYLOAD_N,		/* RFC 2408, Notification		*/
	ISAKMP_PAYLOAD_D,		/* RFC 2408, Delete			*/
	ISAKMP_PAYLOAD_VID,		/* RFC 2408, Vendor ID			*/
	ISAKMP_PAYLOAD_MODECFG_ATTR,
	ISAKMP_PAYLOAD_SAK,		/* RFC 3547, SA KEK			*/
	ISAKMP_PAYLOAD_SAT,		/* RFC 3547, SA TEK			*/
	ISAKMP_PAYLOAD_KD,		/* RFC 3547, Key Download		*/
	ISAKMP_PAYLOAD_SEQNO,		/* RFC 3547, Sequence number		*/
	ISAKMP_PAYLOAD_POP,		/* RFC 3547, Proof of Possession	*/
	ISAKMP_PAYLOAD_NAT_D,		/* RFC 3947, NAT Discovery		*/
	ISAKMP_PAYLOAD_NAT_OA,		/* RFC 3947, NAT Original Address	*/
	ISAKMP_PAYLOAD_NAT_D_OLD = 0x82,
	ISAKMP_PAYLOAD_FRAG = 0x84
};

/* Exchange types.  */
enum isakmp_exchange_enum {
	ISAKMP_EXCHANGE_NONE = 0,
	ISAKMP_EXCHANGE_BASE,
	ISAKMP_EXCHANGE_IDENTITY,
	ISAKMP_EXCHANGE_AUTH_ONLY,
	ISAKMP_EXCHANGE_AGGRESSIVE,
	ISAKMP_EXCHANGE_INFORMATIONAL,
	ISAKMP_EXCHANGE_MODECFG_TRANSACTION,
	ISAKMP_EXCHANGE_IKE_QUICK = 32,
	ISAKMP_EXCHANGE_IKE_NEW_GROUP
};

/* DOI types.  */
enum isakmp_doi_enum {
	ISAKMP_DOI_GENERIC = 0,
	ISAKMP_DOI_IPSEC
};

/* Notify message types (error: 1-16383; status: 16384-65535).  */
enum isakmp_notify_enum {
	ISAKMP_N_INVALID_PAYLOAD_TYPE = 1,
	ISAKMP_N_DOI_NOT_SUPPORTED,
	ISAKMP_N_SITUATION_NOT_SUPPORTED,
	ISAKMP_N_INVALID_COOKIE,
	ISAKMP_N_INVALID_MAJOR_VERSION,
	ISAKMP_N_INVALID_MINOR_VERSION,
	ISAKMP_N_INVALID_EXCHANGE_TYPE,
	ISAKMP_N_INVALID_FLAGS,
	ISAKMP_N_INVALID_MESSAGE_ID,
	ISAKMP_N_INVALID_PROTOCOL_ID,
	ISAKMP_N_INVALID_SPI,
	ISAKMP_N_INVALID_TRANSFORM_ID,
	ISAKMP_N_ATTRIBUTES_NOT_SUPPORTED,
	ISAKMP_N_NO_PROPOSAL_CHOSEN,
	ISAKMP_N_BAD_PROPOSAL_SYNTAX,
	ISAKMP_N_PAYLOAD_MALFORMED,
	ISAKMP_N_INVALID_KEY_INFORMATION,
	ISAKMP_N_INVALID_ID_INFORMATION,
	ISAKMP_N_INVALID_CERT_ENCODING,
	ISAKMP_N_INVALID_CERTIFICATE,
	ISAKMP_N_CERT_TYPE_UNSUPPORTED,
	ISAKMP_N_INVALID_CERT_AUTHORITY,
	ISAKMP_N_INVALID_HASH_INFORMATION,
	ISAKMP_N_AUTHENTICATION_FAILED,
	ISAKMP_N_INVALID_SIGNATURE,
	ISAKMP_N_ADDRESS_NOTIFICATION,
	ISAKMP_N_NOTIFY_SA_LIFETIME,
	ISAKMP_N_CERTIFICATE_UNAVAILABLE,
	ISAKMP_N_UNSUPPORTED_EXCHANGE_TYPE,
	ISAKMP_N_UNEQUAL_PAYLOAD_LENGTHS,
	ISAKMP_N_CONNECTED = 16384,
	ISAKMP_N_IPSEC_RESPONDER_LIFETIME = 24576,
	ISAKMP_N_IPSEC_REPLAY_STATUS,
	ISAKMP_N_IPSEC_INITIAL_CONTACT,
	ISAKMP_N_CISCO_HELLO = 30000,
	ISAKMP_N_CISCO_WWTEBR,
	ISAKMP_N_CISCO_SHUT_UP,
	ISAKMP_N_IOS_KEEP_ALIVE_REQ = 32768,
	ISAKMP_N_IOS_KEEP_ALIVE_ACK,
	ISAKMP_N_R_U_THERE = 36136,
	ISAKMP_N_R_U_THERE_ACK,
	ISAKMP_N_CISCO_LOAD_BALANCE = 40501,
	ISAKMP_N_CISCO_PRESHARED_KEY_HASH = 40503
};

/* Delete with reason values */
/* Note: The values are random, i.e. we don't know them yet */
enum dwr_ike_delete {
	IKE_DELETE_SERVER_SHUTDOWN = 0, /* Peer has been shut down */
	IKE_DELETE_SERVER_REBOOT, /* Peer has been rebooted. */
	IKE_DELETE_MAX_CONNECT_TIME, /* Maximum configured connection time exceeded. */
	IKE_DELETE_BY_USER_COMMAND, /* Manually disconnected by administrator. */
	IKE_DELETE_BY_ERROR, /* Connectivity to Client lost. */
	IKE_DELETE_NO_ERROR, /* Unknown error. */
	IKE_DELETE_IDLE_TIMEOUT, /* Maximum idle time for session exceeded. */
	IKE_DELETE_P2_PROPOSAL_MISMATCH, /* Policy negotiation failed */
	IKE_DELETE_FIREWALL_MISMATCH, /* Firewall policy mismatch. */
	IKE_DELETE_CERT_EXPIRED, /* Certificates used with this connection entry have expired. */
	IKE_DELETE_BY_EXPIRED_LIFETIME, /* Maximum configured lifetime exceeded. */
	DEL_REASON_RESET_SADB /* (found in vpnclient log file) */
};

/* Certificate types.  */
enum isakmp_certificate_enum {
	ISAKMP_CERT_NONE = 0,
	ISAKMP_CERT_PKCS7_X509,
	ISAKMP_CERT_PGP,
	ISAKMP_CERT_DNS_SIG_KEY,
	ISAKMP_CERT_X509_SIG,
	ISAKMP_CERT_X509_KEX_EXCHANGE,
	ISAKMP_CERT_KERBEROS_TOKENS,
	ISAKMP_CERT_CRL,
	ISAKMP_CERT_ARL,
	ISAKMP_CERT_SPKI,
	ISAKMP_CERT_X509_ATTRIBUTE
};

/* IKE attribute types.  */
enum ike_attr_enum {
	IKE_ATTRIB_ENC = 1,
	IKE_ATTRIB_HASH,
	IKE_ATTRIB_AUTH_METHOD,
	IKE_ATTRIB_GROUP_DESC,
	IKE_ATTRIB_GROUP_TYPE,
	IKE_ATTRIB_GROUP_PRIME,
	IKE_ATTRIB_GROUP_GEN_1,
	IKE_ATTRIB_GROUP_GEN_2,
	IKE_ATTRIB_GROUP_CURVE_A,
	IKE_ATTRIB_GROUP_CURVE_B,
	IKE_ATTRIB_LIFE_TYPE,
	IKE_ATTRIB_LIFE_DURATION,
	IKE_ATTRIB_PRF,
	IKE_ATTRIB_KEY_LENGTH,
	IKE_ATTRIB_FIELD_SIZE,
	IKE_ATTRIB_GROUP_ORDER,
	IKE_ATTRIB_BLOCK_SIZE,
	IKE_ATTRIB_NORTEL_CLIENT_ID = 32767
};

/* IKE encryption algorithm IDs.  */
enum ike_enc_enum {
	IKE_ENC_NO_CBC = 0,
	IKE_ENC_DES_CBC,
	IKE_ENC_IDEA_CBC,
	IKE_ENC_BLOWFISH_CBC,
	IKE_ENC_RC5_R16_B16_CBC,
	IKE_ENC_3DES_CBC,
	IKE_ENC_CAST_CBC,
	IKE_ENC_AES_CBC
};

/* IKE hash algorithm IDs.  */
enum ike_hash_enum {
	IKE_HASH_MD5 = 1,
	IKE_HASH_SHA,
	IKE_HASH_TIGER,
	IKE_HASH_SHA2_256,
	IKE_HASH_SHA2_384,
	IKE_HASH_SHA2_512
};

/* IKE authentication method IDs.  */
enum ike_auth_enum {
	IKE_AUTH_PRESHARED = 1,
	IKE_AUTH_DSS,
	IKE_AUTH_RSA_SIG,
	IKE_AUTH_RSA_ENC,
	IKE_AUTH_RSA_ENC_2,
	IKE_AUTH_EL_GAMAL_ENC,
	IKE_AUTH_EL_GAMAL_ENC_REV,
	IKE_AUTH_ECDSA_SIG,
	IKE_AUTH_HybridInitRSA = 64221,
	IKE_AUTH_HybridRespRSA,
	IKE_AUTH_HybridInitDSS,
	IKE_AUTH_HybridRespDSS,
	IKE_AUTH_XAUTHInitPreShared = 65001,
	IKE_AUTH_XAUTHRespPreShared,
	IKE_AUTH_XAUTHInitDSS,
	IKE_AUTH_XAUTHRespDSS,
	IKE_AUTH_XAUTHInitRSA,
	IKE_AUTH_XAUTHRespRSA,
	IKE_AUTH_XAUTHInitRSAEncryption,
	IKE_AUTH_XAUTHRespRSAEncryption,
	IKE_AUTH_XAUTHInitRSARevisedEncryption,
	IKE_AUTH_XAUTHRespRSARevisedEncryption
};

/* IKE group IDs.  */
enum ike_group_enum {
	IKE_GROUP_MODP_768 = 1,
	IKE_GROUP_MODP_1024,
	IKE_GROUP_EC2N_155,
	IKE_GROUP_EC2N_185,
	IKE_GROUP_MODP_1536,
	IKE_GROUP_EC2N_163sect,
	IKE_GROUP_EC2N_163K,
	IKE_GROUP_EC2N_283sect,
	IKE_GROUP_EC2N_283K,
	IKE_GROUP_EC2N_409sect,
	IKE_GROUP_EC2N_409K,
	IKE_GROUP_EC2N_571sect,
	IKE_GROUP_EC2N_571K
};

/* IKE group type IDs.  */
enum ike_group_type_enum {
	IKE_GROUP_TYPE_MODP = 1,
	IKE_GROUP_TYPE_ECP,
	IKE_GROUP_TYPE_EC2N
};

/* IKE life type IDs.  */
enum ike_life_enum {
	IKE_LIFE_TYPE_SECONDS = 1,
	IKE_LIFE_TYPE_K
};

/* IKE NORTEL client version IDs.  */
enum ike_nortel_client_id_enum {
	NORTEL_CLIENT_V00_00 = 0,
	NORTEL_CLIENT_V01_00 = 1,
	NORTEL_CLIENT_V01_05 = 2,
	NORTEL_CLIENT_V02_00 = 3,
	NORTEL_CLIENT_V02_50 = 4,
	NORTEL_CLIENT_V02_60 = 5,
	NORTEL_CLIENT_V02_62 = 6,
	NORTEL_CLIENT_V02_62_47 = 7,
	NORTEL_CLIENT_V03_70 = 8,
	NORTEL_CLIENT_V04_10 = 9,
	NORTEL_CLIENT_V04_15 = 10,
	NORTEL_CLIENT_V04_60 = 11,
	NORTEL_CLIENT_V04_65 = 12,
	NORTEL_CLIENT_V04_65_330 = 13,
	NORTEL_CLIENT_V04_86 = 15,
	NORTEL_CLIENT_V04_91 = 16,
	NORTEL_CLIENT_V05_01 = 20,
	NORTEL_CLIENT_V05_11 = 23,
	NORTEL_CLIENT_V06_01 = 26,
	NORTEL_CLIENT_V06_07 = 30,
	NORTEL_CLIENT_V07_01 = 33,
	NORTEL_CLIENT_VEXTRA = 65535
};

/* IPSEC situation masks.  */
enum isakmp_ipsec_sit_enum {
	ISAKMP_IPSEC_SIT_IDENTITY_ONLY = 0x1,
	ISAKMP_IPSEC_SIT_SECRECY       = 0x2,
	ISAKMP_IPSEC_SIT_INTEGRITY     = 0x4
};

/* IPSEC Identification types.  */
enum isakmp_ipsec_id_enum {
	ISAKMP_IPSEC_ID_RESERVED = 0,
	ISAKMP_IPSEC_ID_IPV4_ADDR,
	ISAKMP_IPSEC_ID_FQDN,
	ISAKMP_IPSEC_ID_USER_FQDN,
	ISAKMP_IPSEC_ID_IPV4_ADDR_SUBNET,
	ISAKMP_IPSEC_ID_IPV6_ADDR,
	ISAKMP_IPSEC_ID_IPV6_ADDR_SUBNET,
	ISAKMP_IPSEC_ID_IPV4_ADDR_RANGE,
	ISAKMP_IPSEC_ID_IPV6_ADDR_RANGE,
	ISAKMP_IPSEC_ID_DER_ASN1_DN,
	ISAKMP_IPSEC_ID_DER_ASN1_GN,
	ISAKMP_IPSEC_ID_KEY_ID
};

/* IPSEC protocol IDs.  */
enum isakmp_ipsec_proto_enum {
	ISAKMP_IPSEC_PROTO_RESERVED = 0,
	ISAKMP_IPSEC_PROTO_ISAKMP,
	ISAKMP_IPSEC_PROTO_IPSEC_AH,
	ISAKMP_IPSEC_PROTO_IPSEC_ESP,
	ISAKMP_IPSEC_PROTO_IPCOMP,
	ISAKMP_IPSEC_PROTO_MODECFG = 512 /* hack for simplicity in debug code */
};

/* IPSEC transform IDs.  */
enum isakmp_ipsec_key_enum {
	ISAKMP_IPSEC_KEY_RESERVED = 0,
	ISAKMP_IPSEC_KEY_IKE
};

/* IPSEC AH IDs.  */
enum isakmp_ipsec_ah_enum {
	ISAKMP_IPSEC_AH_RESERVED = 0,
	ISAKMP_IPSEC_AH_MD5 = 2,
	ISAKMP_IPSEC_AH_SHA,
	ISAKMP_IPSEC_AH_DES,
	ISAKMP_IPSEC_AH_SHA2_256,
	ISAKMP_IPSEC_AH_SHA2_384,
	ISAKMP_IPSEC_AH_SHA2_512,
	ISAKMP_IPSEC_AH_RIPEMD
};

/* IPSEC ESP IDs.  */
enum isakmp_ipsec_esp_enum {
	ISAKMP_IPSEC_ESP_RESERVED = 0,
	ISAKMP_IPSEC_ESP_DES_IV64,
	ISAKMP_IPSEC_ESP_DES,
	ISAKMP_IPSEC_ESP_3DES,
	ISAKMP_IPSEC_ESP_RC5,
	ISAKMP_IPSEC_ESP_IDEA,
	ISAKMP_IPSEC_ESP_CAST,
	ISAKMP_IPSEC_ESP_BLOWFISH,
	ISAKMP_IPSEC_ESP_3IDEA,
	ISAKMP_IPSEC_ESP_DES_IV32,
	ISAKMP_IPSEC_ESP_RC4,
	ISAKMP_IPSEC_ESP_NULL,
	ISAKMP_IPSEC_ESP_AES,
	ISAKMP_IPSEC_ESP_AES_128_CTR,
	ISAKMP_IPSEC_ESP_AES_MARS = 249,
	ISAKMP_IPSEC_ESP_AES_RC6,
	ISAKMP_IPSEC_ESP_AES_RIJNDAEL,
	ISAKMP_IPSEC_ESP_AES_SERPENT,
	ISAKMP_IPSEC_ESP_AES_TWOFISH
};

/* IPSEC attribute types.  */
enum isakmp_ipsec_attr_enum {
	ISAKMP_IPSEC_ATTRIB_SA_LIFE_TYPE = 1,
	ISAKMP_IPSEC_ATTRIB_SA_LIFE_DURATION,
	ISAKMP_IPSEC_ATTRIB_GROUP_DESC,
	ISAKMP_IPSEC_ATTRIB_ENCAP_MODE,
	ISAKMP_IPSEC_ATTRIB_AUTH_ALG,
	ISAKMP_IPSEC_ATTRIB_KEY_LENGTH,
	ISAKMP_IPSEC_ATTRIB_KEY_ROUNDS,
	ISAKMP_IPSEC_ATTRIB_COMP_DICT_SIZE,
	ISAKMP_IPSEC_ATTRIB_COMP_PRIVATE_ALG,
	ISAKMP_IPSEC_ATTRIB_ECN_TUNNEL,
	ISAKMP_IPSEC_ATTRIB_NORTEL_NATT_UDP_PORT = 0x7ffe
};

/* IPSEC compression IDs.  */
enum isakmp_ipsec_ipcomp_enum {
	ISAKMP_IPSEC_IPCOMP_RESERVED = 0,
	ISAKMP_IPSEC_IPCOMP_OUI,
	ISAKMP_IPSEC_IPCOMP_DEFLATE,
	ISAKMP_IPSEC_IPCOMP_LZS,
	ISAKMP_IPSEC_IPCOMP_V42BIS
};

/* IPSEC lifetime attribute values.  */
enum ipsec_life_enum {
	IPSEC_LIFE_SECONDS = 1,
	IPSEC_LIFE_K
};

/* IPSEC encapsulation attribute numbers.  */
enum ipsec_encap_enum {
	IPSEC_ENCAP_TUNNEL = 1,
	IPSEC_ENCAP_TRANSPORT,
	IPSEC_ENCAP_UDP_TUNNEL,
	IPSEC_ENCAP_UDP_TRANSPORT,
	IPSEC_ENCAP_UDP_TUNNEL_OLD = 61443,
	IPSEC_ENCAP_UDP_TRANSPORT_OLD
};

/* IPSEC authentication attribute numbers.  */
enum ipsec_auth_enum {
	IPSEC_AUTH_HMAC_MD5 = 1,
	IPSEC_AUTH_HMAC_SHA,
	IPSEC_AUTH_DES_MAC,
	IPSEC_AUTH_KPDK
};

/* Other numbers.  */
#define ISAKMP_COOKIE_LENGTH		8
#define ISAKMP_VERSION			0x10
/* offsets */
#define ISAKMP_EXCHANGE_TYPE_O		18
#define ISAKMP_I_COOKIE_O		0
#define ISAKMP_R_COOKIE_O		8
#define ISAKMP_MESSAGE_ID_O		20
#define ISAKMP_PAYLOAD_O		28

/* defined in vpnc.c */
extern const unsigned char VID_XAUTH[];
extern const unsigned char VID_DPD[];
extern const unsigned char VID_UNITY[];
extern const unsigned char VID_UNKNOWN[];
extern const unsigned char VID_NATT_00[];
extern const unsigned char VID_NATT_01[];
extern const unsigned char VID_NATT_02[];
extern const unsigned char VID_NATT_02N[];
extern const unsigned char VID_NATT_RFC[];

/* Support for draft-ietf-ipsec-isakmp-mode-cfg-05.txt (yuk).  */
enum isakmp_modecfg_cfg_enum {
	ISAKMP_MODECFG_CFG_REQUEST = 1,
	ISAKMP_MODECFG_CFG_REPLY,
	ISAKMP_MODECFG_CFG_SET,
	ISAKMP_MODECFG_CFG_ACK,
	ISAKMP_MODECFG_CFG_NORTEL_OK,
	ISAKMP_MODECFG_CFG_NORTEL_ERR
};

enum isakmp_modecfg_attrib_enum {
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_ADDRESS = 1,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_NETMASK,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_DNS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_NBNS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_ADDRESS_EXPIRY,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_DHCP,
	ISAKMP_MODECFG_ATTRIB_APPLICATION_VERSION,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_ADDRESS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_NETMASK,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_DNS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_NBNS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_DHCP,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_SUBNET,
	ISAKMP_MODECFG_ATTRIB_SUPPORTED_ATTRIBUTES,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_SUBNET,

	ISAKMP_XAUTH_02_ATTRIB_TYPE = 0x0d,
	ISAKMP_XAUTH_02_ATTRIB_USER_NAME,
	ISAKMP_XAUTH_02_ATTRIB_USER_PASSWORD,
	ISAKMP_XAUTH_02_ATTRIB_PASSCODE,
	ISAKMP_XAUTH_02_ATTRIB_MESSAGE,
	ISAKMP_XAUTH_02_ATTRIB_CHALLENGE,
	ISAKMP_XAUTH_02_ATTRIB_DOMAIN,
	ISAKMP_XAUTH_02_ATTRIB_STATUS,
	ISAKMP_XAUTH_02_ATTRIB_NEXT_PIN,
	ISAKMP_XAUTH_02_ATTRIB_ANSWER, /* TYPE .. ANSWER is excluded from dump */

	ISAKMP_MODECFG_ATTRIB_NORTEL_SPLIT_INC = 0x4000,
	ISAKMP_MODECFG_ATTRIB_NORTEL_DEF_DOMAIN_A = 0x4005,
	ISAKMP_MODECFG_ATTRIB_NORTEL_UNKNOWN_4011 = 0x4011,
	ISAKMP_MODECFG_ATTRIB_NORTEL_CLIENT_ID = 0x4012,
	ISAKMP_MODECFG_ATTRIB_NORTEL_SPLIT_INV = 0x4014,
	ISAKMP_MODECFG_ATTRIB_NORTEL_SPLIT_INV_MODE = 0x4015,
	ISAKMP_MODECFG_ATTRIB_NORTEL_DEF_DOMAIN_B = 0x4018,

	ISAKMP_XAUTH_06_ATTRIB_TYPE = 0x4088,
	ISAKMP_XAUTH_06_ATTRIB_USER_NAME,
	ISAKMP_XAUTH_06_ATTRIB_USER_PASSWORD,
	ISAKMP_XAUTH_06_ATTRIB_PASSCODE,
	ISAKMP_XAUTH_06_ATTRIB_MESSAGE,
	ISAKMP_XAUTH_06_ATTRIB_CHALLENGE,
	ISAKMP_XAUTH_06_ATTRIB_DOMAIN,
	ISAKMP_XAUTH_06_ATTRIB_STATUS,
	ISAKMP_XAUTH_06_ATTRIB_NEXT_PIN,
	ISAKMP_XAUTH_06_ATTRIB_ANSWER, /* TYPE .. ANSWER is excluded from dump */

	ISAKMP_MODECFG_ATTRIB_CISCO_BANNER = 0x7000,
	ISAKMP_MODECFG_ATTRIB_CISCO_SAVE_PW,
	ISAKMP_MODECFG_ATTRIB_CISCO_DEF_DOMAIN,
	ISAKMP_MODECFG_ATTRIB_CISCO_SPLIT_DNS,
	ISAKMP_MODECFG_ATTRIB_CISCO_SPLIT_INC,
	ISAKMP_MODECFG_ATTRIB_CISCO_UDP_ENCAP_PORT,
	ISAKMP_MODECFG_ATTRIB_CISCO_UNKNOWN, /* whatever 0x7006 is... */
	ISAKMP_MODECFG_ATTRIB_CISCO_DO_PFS,
	/* Cisco Ext: Smartcard Disconnect */
	/* Cisco Ext: IKE_CFG_FWTYPE_VENDOR */
	/* Cisco Ext: IKE_CFG_FWTYPE_PRODUCT */
	/* Cisco Ext: IKE_CFG_FWTYPE_CAPABILITIES??? */
	ISAKMP_MODECFG_ATTRIB_CISCO_FW_TYPE,
	ISAKMP_MODECFG_ATTRIB_CISCO_BACKUP_SERVER,
	ISAKMP_MODECFG_ATTRIB_CISCO_DDNS_HOSTNAME,
	ISAKMP_XAUTH_ATTRIB_CISCOEXT_VENDOR = 0x7d88 /* strange cisco things ... need docs! */
};

enum isakmp_modecfg_type_enum { /* draft-ietf-ipsec-isakmp-xauth-05.txt */
	ISAKMP_MODECFG_TYPE_GENERIC,
	ISAKMP_MODECFG_TYPE_RADIUS,
	ISAKMP_MODECFG_TYPE_OTP,
	ISAKMP_MODECFG_TYPE_NTDOMAIN,
	ISAKMP_MODECFG_TYPE_UNIX,
	ISAKMP_MODECFG_TYPE_SECURID,
	ISAKMP_MODECFG_TYPE_AXENT,
	ISAKMP_MODECFG_TYPE_LEEMAH,
	ISAKMP_MODECFG_TYPE_ACTIVECARD,
	ISAKMP_MODECFG_TYPE_DESGOLD,
	ISAKMP_MODECFG_TYPE_TACACS,
	ISAKMP_MODECFG_TYPE_TACACSPLUS,
	ISAKMP_MODECFG_TYPE_SKEY,
	ISAKMP_MODECFG_TYPE_NDS,
	ISAKMP_MODECFG_TYPE_DIAMETER,
	ISAKMP_MODECFG_TYPE_LDAP
};

#endif
