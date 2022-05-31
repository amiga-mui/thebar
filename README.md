# TheBar.mcc

[![Build](https://github.com/amiga-mui/thebar/workflows/CI/badge.svg)](https://github.com/amiga-mui/thebar/actions)
[![License](http://img.shields.io/:license-lgpl2-blue.svg?style=flat)](http://www.gnu.org/licenses/lgpl-2.1.html)

TheBar.mcc is a MUI custom class for Amiga systems for management of multiple
buttons in a toolbar-like environment. It allows to group multiple button together,
allows to hide/sleep/disable a specific button as well as send notifications in
case a button was pressed by the user. It features a multitude of different
settings and the majority of these are configurable for the user via the MUI
preferences system.

TheBar.mcc class was originally developed by Alfonso Ranieri. Since November
2005 it was released under the LGPL license and is now freely available and
further developed by an independent open source developer group.

TheBar.mcc is available for AmigaOS3, AmigaOS4, MorphOS and AROS.

## Downloads/Releases

All releases up to the most current ones can be downloaded from our
[central releases management](https://github.com/amiga-mui/thebar/releases).

## Bug Reports / Enhancement Requests

To report bugs use the [bug/issue tracker](https://github.com/amiga-mui/thebar/issues).

## Manual Installation

1. Extract the archive to a temporary directory.
   ```
   > cd RAM:
   > lha x MCC_TheBar.lha
   ```

2. Go to the "MCC_TheBar/Libs/MUI/<OS>" directory where <OS> is the directory
   matching the operating system you want to install TheBar.mcc for:
   ```
   > cd MCC_TheBar/Libs/MUI/AmigaOS4
   ```

3. copy all #?.mcc and #?.mcp files found in that <OS> directory to the
   global "MUI:libs/mui/" directory on your system partition:
   ```
   > copy #?.mcc MUI:Libs/mui/
   > copy #?.mcp MUI:Libs/mui/
   ```

4. reboot and enjoy the new version ;)

## License / Copyright

```
Copyright (C) 2003-2005 Alfonso Ranieri
Copyright (C) 2005-2022 TheBar Open Source Team
```

TheBar.mcc is distributed and licensed under the GNU Lesser Public License Version 2.1.
See [COPYING](COPYING) for more detailed information.

## Authors

* Alfonso Ranieri
* Gianfranco Gignina
* Jens Maus
* Matthias Rustler
* Thore Böckelmann
