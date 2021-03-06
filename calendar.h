/*
 * calendar.h
 * This file is part of focal, a calendar application for Linux
 * Copyright 2018 Oliver Giles and focal contributors.
 *
 * Focal is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * Focal is distributed without any explicit or implied warranty.
 * You should have received a copy of the GNU General Public License
 * version 3 with focal. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CALENDAR_H
#define CALENDAR_H

#include <glib-object.h>
#include <libical/ical.h>

#define TYPE_CALENDAR (calendar_get_type())
G_DECLARE_DERIVABLE_TYPE(Calendar, calendar, FOCAL, CALENDAR, GObject)

typedef void (*CalendarEachEventCallback)(void* user, icalcomponent* vevent);

struct _CalendarClass {
	GObjectClass parent;
	void (*add_event)(Calendar*, icalcomponent* event);
	void (*delete_event)(Calendar*, icalcomponent* event);
	void (*each_event)(Calendar*, CalendarEachEventCallback callback, void* user);
};

void calendar_add_event(Calendar* self, icalcomponent* event);

void calendar_delete_event(Calendar* self, icalcomponent* event);

void calendar_each_event(Calendar* self, CalendarEachEventCallback callback, void* user);

void calendar_set_email(Calendar* self, const char* email);

const char* calendar_get_email(Calendar* self);

#endif // CALENDAR_H
