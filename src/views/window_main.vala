/**
 * Window main class file
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

namespace com.diegorubin.gforticlient.views {

  public class WindowMain : Window {

    // settings
    private GFortiClientSettings settings;

    // control
    private bool winVisible;

    // widgets
    private Gtk.Grid mainGrid;
    private Gtk.Entry entPath;

    // others components
    private StatusIcon trayicon;
    private Gtk.AttachOptions defaultFlags;

    public WindowMain() {

      settings = new GFortiClientSettings();

      // controls
      winVisible = true;
      defaultFlags = Gtk.AttachOptions.EXPAND | Gtk.AttachOptions.FILL;

      // set status icon
      this.setStatusIcon();

      // window configuration
      this.title = "GFortiClient";
      this.destroy.connect(Gtk.main_quit);

      // widgets
		  mainGrid = new Gtk.Grid();

      // widgets - address
      Gtk.Box box = new Gtk.Box(Gtk.Orientation.HORIZONTAL, 0);

      box.pack_start(new Gtk.Label("Path for FortiClientCLI"), false, false, 10);

      entPath = new Gtk.Entry();
      entPath.set_text(settings.getPath());
      entPath.changed.connect(savePath);
      box.pack_start(entPath, false, false, 10);

      mainGrid.attach(box, 0, 0, 1, 1);
		  this.add(mainGrid);
    }

    public void toggleWindow() {
      this.visible = !this.visible;
      if (this.visible) {
        show_all();
      } else {
        hide();
      }
    }

    private void savePath() {
      settings.setPath(entPath.get_text());
    }

    private void setStatusIcon() {

      trayicon = new StatusIcon.from_stock(Stock.HOME);
      trayicon.set_tooltip_text("GFortiClient");
      trayicon.set_visible(true);

      trayicon.activate.connect(toggleWindow);

    }

  }

}

