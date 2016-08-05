//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/serial.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SERIAL_H_
#define ILS_UTIL_SERIAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ASCII character definitions */
#define CH_NUL 0x00      /* Null                      (Ctrl-@) */
#define CH_SOH 0x01      /* Start of heading          (Ctrl-A) */
#define CH_STX 0x02      /* Start of text             (Ctrl-B) */
#define CH_ETX 0x03      /* End of text               (Ctrl-C) */
#define CH_EOT 0x04      /* End of transmission       (Ctrl-D) */
#define CH_ENQ 0x05      /* Enquiry                   (Ctrl-E) */
#define CH_ACK 0x06      /* Acknowledge               (Ctrl-F) */
#define CH_BEL 0x07      /* Bell                      (Ctrl-G) */
#define CH_BS  0x08      /* Back space                (Ctrl-H) */
#define CH_HT  0x09      /* Horizontal tab            (Ctrl-I) */
#define CH_LF  0x0a      /* Line feed                 (Ctrl-J) */
#define CH_VT  0x0b      /* Vertical tab              (Ctrl-K) */
#define CH_FF  0x0c      /* Form feed                 (Ctrl-L) */
#define CH_CR  0x0d      /* Carriage return           (Ctrl-M) */
#define CH_SO  0x0e      /* Shift out                 (Ctrl-N) */
#define CH_SI  0x0f      /* Shift in                  (Ctrl-O) */
#define CH_DLE 0x10      /* Data link escape          (Ctrl-P) */
#define CH_DC1 0x11      /* Device control 1          (Ctrl-Q) */
#define CH_DC2 0x12      /* Device control 2          (Ctrl-R) */
#define CH_DC3 0x13      /* Device control 3          (Ctrl-S) */
#define CH_DC4 0x14      /* Device control 4          (Ctrl-T) */
#define CH_NAK 0x15      /* Negative acknowledge      (Ctrl-U) */
#define CH_SYN 0x16      /* Synchronous idle          (Ctrl-V) */
#define CH_ETB 0x17      /* End of transmission block (Ctrl-W) */
#define CH_CAN 0x18      /* Cancel                    (Ctrl-X) */
#define CH_EM  0x19      /* End of medium             (Ctrl-Y) */
#define CH_SUB 0x1a      /* Substitute                (Ctrl-Z) */
#define CH_ESC 0x1b      /* Escape                    (Ctrl-[) */
#define CH_FS  0x1c      /* File seperator            (Ctrl-\) */
#define CH_GS  0x1d      /* Group seperator           (Ctrl-]) */
#define CH_RS  0x1e      /* Record seperator          (Ctrl-^) */
#define CH_US  0x1f      /* Unit seperator            (Ctrl-_) */
#define CH_SP  0x20      /* Space                              */
#define CH_DEL 0x7f      /* Delete                             */

typedef struct {
	char port[32];
	int baud_rate;

	char data_bits;
	char stop_bits;
	char parity;

	int scan_interval;
	int idle_timeout;
	int force_dtr_rts_high;
} SERIAL_PARAMETERS;

UTIL_EXPORT int  serial_parameters_create(SERIAL_PARAMETERS **params);
UTIL_EXPORT void serial_parameters_delete(SERIAL_PARAMETERS *params);

UTIL_EXPORT int serial_create(void **handle);
UTIL_EXPORT void serial_delete(void *handle);
UTIL_EXPORT int serial_error(void *handle);

UTIL_EXPORT int serial_clear_buffers(void *handle);
UTIL_EXPORT int serial_bytes_in_queue(void *handle);

UTIL_EXPORT int serial_open(void *handle, SERIAL_PARAMETERS *parameters);
UTIL_EXPORT int serial_close(void *handle);

UTIL_EXPORT int serial_read(void *handle, unsigned char *buffer, int *length, int timeout);
UTIL_EXPORT int serial_read_exact(void *handle, unsigned char *buffer, int length, int timeout);
UTIL_EXPORT int serial_write(void *handle, unsigned char *buffer, int length);

UTIL_EXPORT int serial_port_list(char **names, char **ports, int *count, int maxlen);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SERIAL_H_*/
