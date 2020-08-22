// Fill out your copyright notice in the Description page of Project Settings.


#include "FleePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFleePlayer::AFleePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SringArmComp = CreateDefaultSubobject<USpringArmComponent>(FName("SringArmComp"));
	SringArmComp->TargetArmLength = 400.f;

	MyCamera = CreateDefaultSubobject<UCameraComponent>(FName("MyCamera"));
	MyCamera->SetFieldOfView(110.f);
	/*Mesh1 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	Mesh1->SetSimulatePhysics(true);
	Mesh1->SetupAttachment(RootComponent);*/

	SringArmComp->SetupAttachment(RootComponent);
	MyCamera->SetupAttachment(SringArmComp);
	AddFoaceNumber = 100.f;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.8f;

	bIsCanSpawnPlane = true;
}

// Called when the game starts or when spawned
void AFleePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFleePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveForward(1);
}

// Called to bind functionality to input
void AFleePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&AFleePlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&AFleePlayer::MoveRight);
	PlayerInputComponent->BindAction("Jump",EInputEvent::IE_Pressed,this,&AFleePlayer::Jump);

}

void AFleePlayer::MoveForward(float var)
{
	AddMovementInput(MyCamera->GetForwardVector() * var);
	//UE_LOG(LogTemp, Warning, TEXT("w"));
}

void AFleePlayer::MoveRight(float var)
{
	//AddMovementInput(GetArrowComponent()->GetRightVector()* var);
	AddControllerYawInput(var);
}

