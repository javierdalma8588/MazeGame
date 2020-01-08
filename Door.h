#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class PRACTICA1_API ADoor : public AActor
{
	GENERATED_BODY()
	
private:
	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;


};
