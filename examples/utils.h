
void init_defaults(void);
void init_vars(void);
GS *gs_create(void);
void do_getopt(int argc, char *argv[]);
void usage(const char *params);
int fd_cmd(const char *cmd);
int fd_new_socket(void);
int fd_net_listen(GS_SELECT_CTX *ctx, int fd, uint16_t port);
int fd_net_accept(GS_SELECT_CTX *ctx, int listen_fd);
int fd_net_connect(GS_SELECT_CTX *ctx, int fd, uint32_t ip, uint16_t port);
void stty_set_raw(void);
void stty_reset(void);
void stty_check_esc(GS *gs, char c);
char **mk_env(char **blacklist);

#define VLOG(a...)	do{if (gopt.log_fp == NULL){break;} fprintf(gopt.log_fp, a); }while(0)

/* hack to set rows/columns and allow screen in a screen
 * unset STY - allow screen in a screen
 * set -e STTY - fish shell (unset)
 * fish-shell is a bitch and does not support 'unset' but needs
 * 'set -e' instead. unset will yield 'comand not found' on fish-sh.
 */
#define GS_STTY_INIT_HACK	"stty rows %d columns %d\r"
// #define GS_STTY_INIT_HACK	"stty rows %d columns %d;unset STY; set -e STY\r"
// #define GS_STTY_INIT_HACK	"(stty rows %d columns %d;unset STY; set -e STY)&>/dev/null\r"

#define UTILS_GETOPT_STR	"igqwACTrla:s:k:p:d:e:"