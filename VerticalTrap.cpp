#include "VerticalTrap.h"
#include "TimerManager.h"
#include "PlayerBase.h"

// Sets default values
AVerticalTrap::AVerticalTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

//Fucntion called when the game starts
void AVerticalTrap::BeginPlay()
{
	Super::BeginPlay();
	//Execute the function ChangeDirection after changeTime has passed, and it loops
	GetWorldTimerManager().SetTimer(timerHandle, this, &AVerticalTrap::ChangeDirection, changeTime, true);

	OnActorBeginOverlap.AddDynamic(this, &AVerticalTrap::OnOverlap);

}

// Called every frame
void AVerticalTrap::Tick(float DeltaTime)
{
	//Set the variable movementZ to move at a certain velocity multiply by deltaTime
	float movementZ = velocity * DeltaTime;

	//Move the object on Z using AddActorLocalOffset function
	AddActorLocalOffset(FVector(0, 0, movementZ), true);
}

void AVerticalTrap::ChangeDirection()
{
	//Multiply the velocity to -1 so it goes on the oposite direction
	velocity *= -1;
}

//function to check the overlap between the trap and the player
void AVerticalTrap::OnOverlap(AActor* me, AActor* other)
{
	//cast the other object as a player (to make sure the objects that collides with the trap is a player) so we can damage the player life
	APlayerBase* pb = Cast<APlayerBase>(other);

	//if the cast is not null
	if (pb != nullptr)
	{
		//then we deduct the player life by damage
		pb->life -= damage;
	}
}

