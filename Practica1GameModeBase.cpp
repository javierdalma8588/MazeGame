#include "Practica1GameModeBase.h"
#include "Engine/World.h"

//constructor 
APractica1GameModeBase::APractica1GameModeBase()
{
	//enable the tick function
	PrimaryActorTick.bCanEverTick = true;
}

//called every frame
void APractica1GameModeBase::Tick(float deltaTime)
{
	//check if the amount of the objectives the player has is equal to the amount of objectives it needs
	if (pickedObjectives >= objectivesToPick)
	{
		//if it is then we send it to the win scene
		GetWorld()->ServerTravel("win");
	}
}