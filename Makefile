#/***************************************************************************
#
# TheBar.mcc - Next Generation Toolbar MUI Custom Class
# Copyright (C) 2003-2005 Alfonso Ranieri
# Copyright (C) 2005-2009 by TheBar.mcc Open Source Team
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# TheBar class Support Site:  http://www.sf.net/projects/thebar
#
# $Id$
#
#***************************************************************************/

.PHONY: all
all: button mcc mcp

.PHONY: button
button:
	@echo "Generating TheButton.mcc..."
	@$(MAKE) -C mcc/button --no-print-directory
	@echo "Done."

.PHONY: mcc
mcc:
	@ echo "Generating TheBar.mcc and TheBarVirt.mcc..."
	@$(MAKE) -C mcc --no-print-directory
	@echo "Done."

.PHONY: mcp
mcp:
	@ echo "Generating TheBar.mcp..."
	@$(MAKE) -C mcp --no-print-directory
	@echo "Done."

.PHONY: clean
clean:
	@echo "Cleaning..."
	@$(MAKE) -C mcc/button --no-print-directory clean
	@$(MAKE) -C mcc --no-print-directory clean
	@$(MAKE) -C mcp --no-print-directory clean
	@echo "Done."

.PHONY: cleanall
cleanall:
	@echo "Cleaning all..."
	@$(MAKE) -C mcc/button --no-print-directory cleanall
	@$(MAKE) -C mcc --no-print-directory cleanall
	@$(MAKE) -C mcp --no-print-directory cleanall
	@echo "Done."

.PHONY: install
install:
	@echo "Installing all..."
	@$(MAKE) -C mcc/button --no-print-directory install
	@$(MAKE) -C mcc --no-print-directory install
	@$(MAKE) -C mcp --no-print-directory install
	@avail flush
	@echo "Done."

