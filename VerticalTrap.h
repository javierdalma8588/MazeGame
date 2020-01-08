#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VerticalTrap.generated.h"

UCLASS()
class PRACTICA1_API AVerticalTrap : public AActor
{
	GENERATED_BODY()

protected:
	//timehandle to set the time to move the object on a different direction
	FTimerHandle timerHandle;

	//function BeginPlay and Change direction
	virtual void BeginPlay() override;
	void ChangeDirection();

public:	
	//Variable oif the object movement speed
	//Assign the property o EditAnywhere so the user can change anything he wants on the Blueprint
	UPROPERTY(EditAnywhere)
	float velocity;

	//variable to set the amount of time that it takes so the object changes direction
	UPROPERTY(EditAnywhere)
	float changeTime;

	//variable to set the amount of damage the player will get
	UPROPERTY(EditAnywhere)
	float damage;

	//Set default values for actor properties
	AVerticalTrap();

	void Tick(float DeltaTime) override;

	//UFunction enables the events system on unreal
	UFUNCTION()
		//function to check collision between objects
	void OnOverlap(AActor* me, AActor* other);
};
