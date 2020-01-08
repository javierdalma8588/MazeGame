#include "Door.h"
#include "PlayerBase.h"

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ADoor::OnOverlap);
}

//function to check the overlap between the trap and the player
void ADoor::OnOverlap(AActor* me, AActor* other)
{
	//cast the other object as a player (to make sure the objects that collides with the trap is a player) so we can damage the player life
	APlayerBase* pb = Cast<APlayerBase>(other);

	//if the cast is not null
	if (pb != nullptr && pb->keys > 0)
	{
		//decrease the amount of keys by 1
		pb->keys--;

		//destroy the object key
		Destroy();
	}
}


