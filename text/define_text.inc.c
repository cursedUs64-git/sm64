// == dialog ==
// (defines en_dialog_table etc.)

#define DEFINE_DIALOG(id, _1, _2, _3, _4, str) \
     const u8 dialog_text_ ## id[] = { str };

#include "dialogs.h"

#undef DEFINE_DIALOG
#define DEFINE_DIALOG(id, unused, linesPerBox, leftOffset, width, _) \
     const struct DialogEntry dialog_entry_ ## id = { \
        unused, linesPerBox, leftOffset, width, dialog_text_ ## id \
    };

#include "dialogs.h"

#undef DEFINE_DIALOG
#define DEFINE_DIALOG(id, _1, _2, _3, _4, _5) &dialog_entry_ ## id,

const struct DialogEntry *const seg2_dialog_table[] = {
#include "dialogs.h"
    NULL
};


// == courses ==
// (defines en_course_name_table etc.)
// The game duplicates this in levels/menu/leveldata.c in EU, so we split
// it out into a separate include file.

#define COURSE_TABLE seg2_course_name_table
#include "define_courses.inc.c"

// == acts ==
// (defines en_act_name_table etc.)

#define COURSE_ACTS(id, name, a,b,c,d,e,f) \
     const u8 act_name_ ## id ## _1[] = { a }; \
     const u8 act_name_ ## id ## _2[] = { b }; \
     const u8 act_name_ ## id ## _3[] = { c }; \
     const u8 act_name_ ## id ## _4[] = { d }; \
     const u8 act_name_ ## id ## _5[] = { e }; \
     const u8 act_name_ ## id ## _6[] = { f };

#define SECRET_STAR(id, name)
#define CASTLE_SECRET_STARS(str)

#undef EXTRA_TEXT
#define EXTRA_TEXT(id, str) \
     const u8 extra_text_ ## id[] = { str };

#include "courses.h"

#undef COURSE_ACTS
#undef EXTRA_TEXT

#define COURSE_ACTS(id, name, a,b,c,d,e,f) \
    act_name_ ## id ## _1, act_name_ ## id ## _2, act_name_ ## id ## _3, \
    act_name_ ## id ## _4, act_name_ ## id ## _5, act_name_ ## id ## _6,
#define EXTRA_TEXT(id, str) extra_text_ ## id,

const u8 *const seg2_act_name_table[] = {
#include "courses.h"
    NULL
};
