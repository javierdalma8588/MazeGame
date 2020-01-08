#include "PlayerBase.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"

//Initialize the constructor
APlayerBase::APlayerBase()
{
	//Enable Tick function
	PrimaryActorTick.bCanEverTick = true;

	//initialize the values of velocity, rotationVelocity, respawns, life, keys
	velocity = 500;
	rotationVelocity = 180;
	life = 100;
	respawns = 2;
	keys = 0;
}

void APlayerBase::BeginPlay()
{
	//ass BeginPlay was override we need to call the base BeginPlay function otherwise it won't work
	Super::BeginPlay();

	//store the initial position of the player at the initialPosition variable getting the position with GetActorLocation()
	initialPosition = GetActorLocation();

	//store the initial rotation of the player at the initialPosition variable getting the position with GetActorRotation()
	initialRotation = GetActorRotation();

	//set the initiallife to the life the player has when it starts
	initialLife = life;
}


//Function to get the player Input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* inputComponent)
{
	//this one takes the forward axis and calls the function of ForwardAxis
	InputComponent->BindAxis("Forward", this, &APlayerBase::ForwardAxis);
	
	//this one takes the side axis and calls the function of SideAxis
	InputComponent->BindAxis("Side", this, &APlayerBase::SideAxis);
}

void APlayerBase::ForwardAxis(float axis)
{
	//variable to set the movement of the player, it gets the axis multiply by the velocity parameter and multiply by the DeltaSecods(FPS)
	float movementX = axis * velocity * GetWorld()->GetDeltaSeconds();
	
	//set the movement with the function AddActorLocalOffset and assign the movementX variable to the x axis of the vector
	AddActorLocalOffset(FVector(movementX, 0, 0), true);
}

void APlayerBase::SideAxis(float axis)
{
	//variable to set the rotation of the player, it gets the axis multiply by the rotationVelocity parameter and multiply by the DeltaSecods(FPS)
	float rotationY = axis * rotationVelocity * GetWorld()->GetDeltaSeconds();

	//set the movement with the function AddActorLocalRotation and assign the rotationY variable to the y axis of the vector
	AddActorLocalRotation(FRotator(0, rotationY,0));
}

void APlayerBase::Tick(float DeltaTime)
{
	//We check if the life of the player is less or equal to cero
	if (life <= 0)
	{
		if (respawns > 0)
		{
			//respawn the actor on the initial position
			SetActorLocation(initialPosition);

			//respwn the actor on the initial rotation
			SetActorRotation(initialRotation);

			//reset the life to the original life
			life = initialLife;

			//Decrease the respawn value minus 1
			respawns--;
		}
		else
		{
			//if we have no respawns left then  we destroy the player
			Destroy();
		}
	}
}

