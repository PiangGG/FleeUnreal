// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FleePlayer.generated.h"

UCLASS()
class FLEEUNREAL_API AFleePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFleePlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Player")
	class UStaticMeshComponent *Mesh1;*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player")
		class USpringArmComponent* SringArmComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player")
		class UCameraComponent* MyCamera;

	void MoveForward(float var);
	void MoveRight(float var);
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player")
		float AddFoaceNumber;

	bool bIsCanSpawnPlane;
};