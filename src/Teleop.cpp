#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

void DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void DevBot::TeleopPeriodic() {
	// Drive
	robotDrive.ArcadeDrive
	(
		-0.5*driver.GetRawAxis(4),		// Lateral movement
		-0.5*driver.GetRawAxis(1)		// Forward movement
	);

	// Set real motor values based off of the fake ones
	UpdateMotors();

	Wait(0.005); // Give the CPU some time to breathe so it doesn't explode.
}
