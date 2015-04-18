/**
 * Main application file
 *
 * This file is part of gforticlient client.
 *
 * Copyright (C) 2015 Diego Rubin <contato@diegorubin.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

using Gtk;

namespace com.diegorubin.gforticlient {

  public class Application: GLib.Object {

    protected views.WindowMain windowMain;

    public void run( string[] args ) {

      Gdk.threads_init();
      Gtk.init( ref args );

      windowMain = new views.WindowMain();
      windowMain.show_all();

      // Enter the Glib eventloop
      // Everything from this point on is completely signal based
      Gdk.threads_enter();
      Gtk.main();
      Gdk.threads_leave();
    }
  }

  public static int main ( string[] args ) {
    var application = new Application();
    application.run( args );

    return 0;
  }
}

