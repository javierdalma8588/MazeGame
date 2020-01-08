#include "CheckPoint.h"
#include "PlayerBase.h"

// Called when the game starts or when spawned
void ACheckPoint::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACheckPoint::OnOverlap);
}

void ACheckPoint::OnOverlap(AActor* me, AActor* other)
{
	//cast the other object as a player (to make sure the objects that collides with the trap is a player) so web can set new position of respawn
	APlayerBase* pb = Cast<APlayerBase>(other);

	//Check if it is not null and check if the checkpoint he player has stored is not the same
	if (pb != nullptr && pb->currentCheckPoint != this)
	{
		//set the initial position to be the position where it touched the checkpoint
		pb->initialPosition = GetActorLocation();

		//and we do the same to the rotation
		pb->initialRotation = GetActorRotation();
		
		//check if current checkpoint is diffent of null
		if (pb->currentCheckPoint != nullptr)
		{
			//move up the previous Checkpoint
			pb->currentCheckPoint->AddActorLocalOffset(FVector(0, 0, 20));
		}

		//assign his checkpoint to player current checkpoint
		pb->currentCheckPoint = this;

		//just and effect as if the player pushed a button
		AddActorLocalOffset(FVector(0, 0, -20));
	}
}


