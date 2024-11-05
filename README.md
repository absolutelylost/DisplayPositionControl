# DisplayPositionControl
This code was written with assistance of Google's bard, Stack Overflow, and library documentation to move displays into specific positions based on stored array entries. This is for precise placement not available in display settings.
The program may need to be run 3 times to fully accomplish the move due to the snapping mechanic forcing rearrangements as changes are made.

Executables can be found in ./build/Debug/
* MonitorChanges shows the current coordinates of each display as numbered in the system.
* PerformPlacementChanges handles moving the displays into a configuration specified in code.

Future Changes:
* move screen coordinates into a config file
* have script, within limit, until the correct configuration requirements are met
