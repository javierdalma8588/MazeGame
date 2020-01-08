#include "ObjectiveToPick.h"
#include "PlayerBase.h"
#include "Engine/World.h"
#include "Practica1GameModeBase.h"

void AObjectiveToPick::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AObjectiveToPick::OnOverlap);
}

void AObjectiveToPick::OnOverlap(AActor* me, AActor* other)
{
	//cast the other object as a player (to make sure the objects that collides with the trap is a player) so we can damage the player life
	APlayerBase* pb = Cast<APlayerBase>(other);

	//if the cast is not null
	if (pb != nullptr)
	{
		//we acces the game mode
		AGameModeBase* gameModeBase = GetWorld()->GetAuthGameMode();

		//then we cast it to the game mode we want
		APractica1GameModeBase* gameMode = Cast<APractica1GameModeBase>(gameModeBase);

		//We check if it's not null
		if (gameMode != nullptr)
		{
			//we aument the variable of the picked objectives from the game mode
			gameMode->pickedObjectives++;

			//and we destroy the object
			Destroy();
		}
	}
}

