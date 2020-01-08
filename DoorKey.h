#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorKey.generated.h"

UCLASS()
class PRACTICA1_API ADoorKey : public AActor
{
	GENERATED_BODY()

private:
	//function to check the collision of the door key
	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;
};
