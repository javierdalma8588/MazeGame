#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBase.generated.h"

UCLASS()
class PRACTICA1_API APlayerBase : public APawn
{
	GENERATED_BODY()

protected:
	//Runs at the begining
	void BeginPlay() override;

public:
	//create the pointer variable of the player current checkpoint
	//set visibleAnywhere so it can be checked on the editor
	class ACheckPoint* currentCheckPoint;

	//Create the variables velocity, rotationVelocity, life, initialLife, keys
	//Assign the property EditAnywhere so the user can change anything he wants on the Blueprint

	float initialLife;
	FVector initialPosition;
	FRotator initialRotation;
	int keys;

	UPROPERTY(EditAnywhere)
	int respawns;

	UPROPERTY(EditAnywhere)
	float life;

	UPROPERTY(EditAnywhere)
	float velocity;

	UPROPERTY(EditAnywhere)
	float rotationVelocity;

	//Set default values for actor properties
	APlayerBase();

	//Get the function to get the player Inputs
	void SetupPlayerInputComponent(class UInputComponent* inputComponent) override;

	//Create the functions to move and rotate
	void ForwardAxis(float axis);
	void SideAxis(float axis);

	void Tick(float DeltaTime) override;
	
};
