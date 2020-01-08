// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckPoint.generated.h"

UCLASS()
class PRACTICA1_API ACheckPoint : public AActor
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
