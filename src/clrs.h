#ifndef _CLRS_H
#define _CLRS_H
#define CLR(code) "\33[" code "m"

#define CLR_RESET     CLR("0")
#define CLR_BOLD      CLR("1")
#define CLR_DIM       CLR("2")
#define CLR_UNDERLINE CLR("4")
#define CLR_BLINK     CLR("5")
#define CLR_REVERSE   CLR("7")
#define CLR_HIDDEN    CLR("8")

#define CLR_BLACK   CLR("30")
#define CLR_RED     CLR("31")
#define CLR_GREEN   CLR("32")
#define CLR_YELLOW  CLR("33")
#define CLR_BLUE    CLR("34")
#define CLR_MAGENTA CLR("35")
#define CLR_CYAN    CLR("36")
#define CLR_WHITE   CLR("37")

#define CLR_BG_BLACK   CLR("40")
#define CLR_BG_RED     CLR("41")
#define CLR_BG_GREEN   CLR("42")
#define CLR_BG_YELLOW  CLR("43")
#define CLR_BG_BLUE    CLR("44")
#define CLR_BG_MAGENTA CLR("45")
#define CLR_BG_CYAN    CLR("46")
#define CLR_BG_WHITE   CLR("47")
#endif /* _CLRS_H */
