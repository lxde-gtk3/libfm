/* fm-actions.h generated by valac 0.34.7, the Vala compiler, do not modify */


#ifndef __FM_ACTIONS_H__
#define __FM_ACTIONS_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <fm-file-info.h>
#include <gio/gio.h>

G_BEGIN_DECLS


#define FM_TYPE_FILE_ACTION_TYPE (fm_file_action_type_get_type ())

#define FM_TYPE_FILE_ACTION_OBJECT (fm_file_action_object_get_type ())
#define FM_FILE_ACTION_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FM_TYPE_FILE_ACTION_OBJECT, FmFileActionObject))
#define FM_FILE_ACTION_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FM_TYPE_FILE_ACTION_OBJECT, FmFileActionObjectClass))
#define FM_IS_FILE_ACTION_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FM_TYPE_FILE_ACTION_OBJECT))
#define FM_IS_FILE_ACTION_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FM_TYPE_FILE_ACTION_OBJECT))
#define FM_FILE_ACTION_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FM_TYPE_FILE_ACTION_OBJECT, FmFileActionObjectClass))

typedef struct _FmFileActionObject FmFileActionObject;
typedef struct _FmFileActionObjectClass FmFileActionObjectClass;
typedef struct _FmFileActionObjectPrivate FmFileActionObjectPrivate;
typedef struct _FmFileActionCondition FmFileActionCondition;

#define FM_TYPE_FILE_ACTION_TARGET (fm_file_action_target_get_type ())

#define FM_TYPE_FILE_ACTION (fm_file_action_get_type ())
#define FM_FILE_ACTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FM_TYPE_FILE_ACTION, FmFileAction))
#define FM_FILE_ACTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FM_TYPE_FILE_ACTION, FmFileActionClass))
#define FM_IS_FILE_ACTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FM_TYPE_FILE_ACTION))
#define FM_IS_FILE_ACTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FM_TYPE_FILE_ACTION))
#define FM_FILE_ACTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FM_TYPE_FILE_ACTION, FmFileActionClass))

typedef struct _FmFileAction FmFileAction;
typedef struct _FmFileActionClass FmFileActionClass;
typedef struct _FmFileActionPrivate FmFileActionPrivate;
typedef struct _FmFileActionProfile FmFileActionProfile;

#define FM_TYPE_FILE_ACTION_MENU (fm_file_action_menu_get_type ())
#define FM_FILE_ACTION_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FM_TYPE_FILE_ACTION_MENU, FmFileActionMenu))
#define FM_FILE_ACTION_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FM_TYPE_FILE_ACTION_MENU, FmFileActionMenuClass))
#define FM_IS_FILE_ACTION_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FM_TYPE_FILE_ACTION_MENU))
#define FM_IS_FILE_ACTION_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FM_TYPE_FILE_ACTION_MENU))
#define FM_FILE_ACTION_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FM_TYPE_FILE_ACTION_MENU, FmFileActionMenuClass))

typedef struct _FmFileActionMenu FmFileActionMenu;
typedef struct _FmFileActionMenuClass FmFileActionMenuClass;
typedef struct _FmFileActionMenuPrivate FmFileActionMenuPrivate;

#define FM_TYPE_FILE_ACTION_ITEM (fm_file_action_item_get_type ())
#define FM_FILE_ACTION_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FM_TYPE_FILE_ACTION_ITEM, FmFileActionItem))
#define FM_FILE_ACTION_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FM_TYPE_FILE_ACTION_ITEM, FmFileActionItemClass))
#define FM_IS_FILE_ACTION_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FM_TYPE_FILE_ACTION_ITEM))
#define FM_IS_FILE_ACTION_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FM_TYPE_FILE_ACTION_ITEM))
#define FM_FILE_ACTION_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FM_TYPE_FILE_ACTION_ITEM, FmFileActionItemClass))

typedef struct _FmFileActionItem FmFileActionItem;
typedef struct _FmFileActionItemClass FmFileActionItemClass;
typedef struct _FmFileActionItemPrivate FmFileActionItemPrivate;

#define FM_TYPE_FILE_ACTION_CAPABILITY (fm_file_action_capability_get_type ())

#define FM_TYPE_FILE_ACTION_EXEC_MODE (fm_file_action_exec_mode_get_type ())

typedef enum  {
	FM_FILE_ACTION_TYPE_NONE,
	FM_FILE_ACTION_TYPE_ACTION,
	FM_FILE_ACTION_TYPE_MENU
} FmFileActionType;

struct _FmFileActionObject {
	GObject parent_instance;
	FmFileActionObjectPrivate * priv;
	FmFileActionType type;
	gchar* id;
	gchar* name;
	gchar* tooltip;
	gchar* icon;
	gchar* desc;
	gboolean enabled;
	gboolean hidden;
	gchar* suggested_shortcut;
	FmFileActionCondition* condition;
	gboolean has_parent;
};

struct _FmFileActionObjectClass {
	GObjectClass parent_class;
};

typedef enum  {
	FM_FILE_ACTION_TARGET_NONE,
	FM_FILE_ACTION_TARGET_CONTEXT = 1,
	FM_FILE_ACTION_TARGET_LOCATION = 1 << 1,
	FM_FILE_ACTION_TARGET_TOOLBAR = 1 << 2
} FmFileActionTarget;

struct _FmFileAction {
	FmFileActionObject parent_instance;
	FmFileActionPrivate * priv;
	FmFileActionTarget target;
	gchar* toolbar_label;
	GList* profiles;
};

struct _FmFileActionClass {
	FmFileActionObjectClass parent_class;
};

struct _FmFileActionMenu {
	FmFileActionObject parent_instance;
	FmFileActionMenuPrivate * priv;
	gchar** items_list;
	gint items_list_length1;
	GList* cached_children;
};

struct _FmFileActionMenuClass {
	FmFileActionObjectClass parent_class;
};

struct _FmFileActionItem {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FmFileActionItemPrivate * priv;
	gchar* name;
	gchar* desc;
	gchar* icon;
	FmFileActionObject* action;
	FmFileActionProfile* profile;
	GList* children;
};

struct _FmFileActionItemClass {
	GTypeClass parent_class;
	void (*finalize) (FmFileActionItem *self);
};

typedef enum  {
	FM_FILE_ACTION_CAPABILITY_OWNER = 0,
	FM_FILE_ACTION_CAPABILITY_READABLE = 1 << 1,
	FM_FILE_ACTION_CAPABILITY_WRITABLE = 1 << 2,
	FM_FILE_ACTION_CAPABILITY_EXECUTABLE = 1 << 3,
	FM_FILE_ACTION_CAPABILITY_LOCAL = 1 << 4
} FmFileActionCapability;

struct _FmFileActionCondition {
	gchar** only_show_in;
	gint only_show_in_length1;
	gchar** not_show_in;
	gint not_show_in_length1;
	gchar* try_exec;
	gchar* show_if_registered;
	gchar* show_if_true;
	gchar* show_if_running;
	gchar** mime_types;
	gint mime_types_length1;
	gchar** base_names;
	gint base_names_length1;
	gboolean match_case;
	gchar selection_count_cmp;
	gint selection_count;
	gchar** schemes;
	gint schemes_length1;
	gchar** folders;
	gint folders_length1;
	FmFileActionCapability capabilities;
};

typedef enum  {
	FM_FILE_ACTION_EXEC_MODE_NORMAL,
	FM_FILE_ACTION_EXEC_MODE_TERMINAL,
	FM_FILE_ACTION_EXEC_MODE_EMBEDDED,
	FM_FILE_ACTION_EXEC_MODE_DISPLAY_OUTPUT
} FmFileActionExecMode;

struct _FmFileActionProfile {
	gchar* id;
	gchar* name;
	gchar* exec;
	gchar* path;
	FmFileActionExecMode exec_mode;
	gboolean startup_notify;
	gchar* startup_wm_class;
	gchar* exec_as;
	FmFileActionCondition* condition;
};


GType fm_file_action_type_get_type (void) G_GNUC_CONST;
GType fm_file_action_object_get_type (void) G_GNUC_CONST;
void fm_file_action_condition_free (FmFileActionCondition* self);
FmFileActionObject* fm_file_action_object_new (void);
FmFileActionObject* fm_file_action_object_construct (GType object_type);
FmFileActionObject* fm_file_action_object_new_from_key_file (GKeyFile* kf);
FmFileActionObject* fm_file_action_object_construct_from_key_file (GType object_type, GKeyFile* kf);
GType fm_file_action_target_get_type (void) G_GNUC_CONST;
GType fm_file_action_get_type (void) G_GNUC_CONST;
void fm_file_action_profile_free (FmFileActionProfile* self);
FmFileAction* fm_file_action_new (const gchar* desktop_id);
FmFileAction* fm_file_action_construct (GType object_type, const gchar* desktop_id);
FmFileAction* fm_file_action_new_from_keyfile (GKeyFile* kf);
FmFileAction* fm_file_action_construct_from_keyfile (GType object_type, GKeyFile* kf);
gboolean fm_file_action_match (FmFileAction* self, GList* files, FmFileActionProfile** matched_profile);
GType fm_file_action_menu_get_type (void) G_GNUC_CONST;
FmFileActionMenu* fm_file_action_menu_new (const gchar* desktop_id);
FmFileActionMenu* fm_file_action_menu_construct (GType object_type, const gchar* desktop_id);
FmFileActionMenu* fm_file_action_menu_new_from_keyfile (GKeyFile* kf);
FmFileActionMenu* fm_file_action_menu_construct_from_keyfile (GType object_type, GKeyFile* kf);
gboolean fm_file_action_menu_match (FmFileActionMenu* self, GList* files);
void fm_file_action_menu_cache_children (FmFileActionMenu* self, GList* files, gchar** items_list, int items_list_length1);
gpointer fm_file_action_item_ref (gpointer instance);
void fm_file_action_item_unref (gpointer instance);
GParamSpec* fm_param_spec_file_action_item (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fm_value_set_file_action_item (GValue* value, gpointer v_object);
void fm_value_take_file_action_item (GValue* value, gpointer v_object);
gpointer fm_value_get_file_action_item (const GValue* value);
GType fm_file_action_item_get_type (void) G_GNUC_CONST;
FmFileActionItem* fm_file_action_item_new_for_action_object (FmFileActionObject* action_obj, GList* files);
FmFileActionItem* fm_file_action_item_new_from_action (FmFileAction* action, FmFileActionProfile* profile, GList* files);
FmFileActionItem* fm_file_action_item_construct_from_action (GType object_type, FmFileAction* action, FmFileActionProfile* profile, GList* files);
FmFileActionItem* fm_file_action_item_new_from_menu (FmFileActionMenu* menu, GList* files);
FmFileActionItem* fm_file_action_item_construct_from_menu (GType object_type, FmFileActionMenu* menu, GList* files);
const gchar* fm_file_action_item_get_name (FmFileActionItem* self);
const gchar* fm_file_action_item_get_desc (FmFileActionItem* self);
const gchar* fm_file_action_item_get_icon (FmFileActionItem* self);
const gchar* fm_file_action_item_get_id (FmFileActionItem* self);
FmFileActionTarget fm_file_action_item_get_target (FmFileActionItem* self);
gboolean fm_file_action_item_is_menu (FmFileActionItem* self);
gboolean fm_file_action_item_is_action (FmFileActionItem* self);
gboolean fm_file_action_item_launch (FmFileActionItem* self, GAppLaunchContext* ctx, GList* files, gchar** output);
GList* fm_file_action_item_get_sub_items (FmFileActionItem* self);
GList* fm_get_actions_for_files (GList* files);
void fm_file_actions_set_desktop_env (const gchar* env);
void _fm_file_actions_init (void);
void _fm_file_actions_finalize (void);
GType fm_file_action_capability_get_type (void) G_GNUC_CONST;
FmFileActionCondition* fm_file_action_condition_new (GKeyFile* kf, const gchar* group);
gboolean fm_file_action_condition_match (FmFileActionCondition* self, GList* files);
GType fm_file_action_exec_mode_get_type (void) G_GNUC_CONST;
FmFileActionProfile* fm_file_action_profile_new (GKeyFile* kf, const gchar* profile_name);
gboolean fm_file_action_profile_launch (FmFileActionProfile* self, GAppLaunchContext* ctx, GList* files, gchar** output);
gboolean fm_file_action_profile_match (FmFileActionProfile* self, GList* files);
gchar* fm_file_action_parameters_expand (const gchar* templ, GList* files, gboolean for_display, FmFileInfo* first_file);
gboolean fm_file_action_parameters_is_plural (const gchar* exec);


G_END_DECLS

#endif