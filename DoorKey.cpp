#include "DoorKey.h"
#include "PlayerBase.h"

void ADoorKey::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ADoorKey::OnOverlap);
}

void ADoorKey::OnOverlap(AActor* me, AActor* other)
{
	//cast the other object as a player (to make sure the objects that collides with the trap is a player) so we can damage the player life
	APlayerBase* pb = Cast<APlayerBase>(other);

	//if the cast is not null
	if (pb != nullptr)
	{
		//increment the amount of keys by 1
		pb->keys++;

		//destroy the object key
		Destroy();
	}
}



