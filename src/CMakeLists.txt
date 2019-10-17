# set the source
SET( pref ${CMAKE_CURRENT_SOURCE_DIR} )
SET( MDO ${pref}/Model/DerivedObjects )
SET( src	${pref}/Model/Object.cpp
			${pref}/Model/GameState.cpp
			${pref}/Model/GameException.cpp
			${pref}/Model/SpaceInvaders.cpp
				${MDO}/Player.cpp
				${MDO}/Alien.cpp
				${MDO}/Bullet.cpp
				${MDO}/Shield.cpp
				${MDO}/PowerUp.cpp
				${MDO}/DerivedPowerUps/LaserGun.cpp
				${MDO}/DerivedPowerUps/Points.cpp
				${MDO}/DerivedPowerUps/ExtraLife.cpp
				${MDO}/DerivedPowerUps/Freeze.cpp
				${MDO}/DerivedPowerUps/SlowMotion.cpp
				${MDO}/DerivedPowerUps/DoubleBulletSpeed.cpp
				${MDO}/DerivedPowerUps/NewShields.cpp				
			${pref}/View/GameWindow.cpp
			${pref}/View/GWSI.cpp
			${pref}/View/OutputFactory.cpp
			${pref}/Controller/GameInput.cpp
			${pref}/Controller/GISI.cpp			
)

# generate the executable
ADD_EXECUTABLE( Space-Invaders	main.cpp	${src} )
TARGET_LINK_LIBRARIES( Space-Invaders	sfml-system sfml-window sfml-graphics ) 
INSTALL( TARGETS Space-Invaders RUNTIME DESTINATION ${BIN_INSTALL_LOCATION} )
