// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlane.generated.h"

UCLASS()
class FLEEUNREAL_API AMyPlane : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPlane();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		float PlaneLength;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		float PlaneWidth;*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		class USceneComponent* SceneComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		class USceneComponent* SceneCompEnd1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		class USceneComponent* SceneCompEnd2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		class UStaticMeshComponent* Mesh1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		class UStaticMeshComponent* Mesh2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		class UBoxComponent* Box1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		class UBoxComponent* Box2;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		class UBoxComponent* Box3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		FVector SpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Plane")
		FRotator SpawnRotator;

	UFUNCTION()
		void OnBox1OverlapBegin(class UPrimitiveComponent* ActorComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnBox1OverlapEnd(class UPrimitiveComponent* ActorComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnBox2OverlapBegin(class UPrimitiveComponent* ActorComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnBox2OverlapEnd(class UPrimitiveComponent* ActorComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UFUNCTION()
		void OnBox3OverlapBegin(class UPrimitiveComponent* ActorComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnBox3OverlapEnd(class UPrimitiveComponent* ActorComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};