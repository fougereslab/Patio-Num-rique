-- public."Devices" definition

-- Drop table

-- DROP TABLE public."Devices";

CREATE TABLE public."Devices" (
	"ID" uuid NOT NULL,
	"Name" text NULL,
	"Description" text NULL,
	"CreatedOn" timestamp NOT NULL,
	"ModifiedOn" timestamp NOT NULL,
	"DisabledOn" timestamp NULL,
	"CreatedBy" uuid NOT NULL,
	"ModifiedBy" uuid NOT NULL,
	"OwnerId" uuid NOT NULL,
	"IsDisabled" bool NOT NULL,
	"DeviceType" int4 NOT NULL,
	CONSTRAINT "PK_Devices" PRIMARY KEY ("ID")
);


-- public."PredefinedCommands" definition

-- Drop table

-- DROP TABLE public."PredefinedCommands";

CREATE TABLE public."PredefinedCommands" (
	"ID" uuid NOT NULL,
	"Name" text NULL,
	"Description" text NULL,
	"CreatedOn" timestamp NOT NULL,
	"ModifiedOn" timestamp NOT NULL,
	"DisabledOn" timestamp NULL,
	"CreatedBy" uuid NOT NULL,
	"ModifiedBy" uuid NOT NULL,
	"OwnerId" uuid NOT NULL,
	"IsDisabled" bool NOT NULL,
	CONSTRAINT "PK_PredefinedCommands" PRIMARY KEY ("ID")
);


-- public."Profiles" definition

-- Drop table

-- DROP TABLE public."Profiles";

CREATE TABLE public."Profiles" (
	"ID" uuid NOT NULL,
	"Name" text NULL,
	"Description" text NULL,
	"CreatedOn" timestamp NOT NULL,
	"ModifiedOn" timestamp NOT NULL,
	"DisabledOn" timestamp NULL,
	"CreatedBy" uuid NOT NULL,
	"ModifiedBy" uuid NOT NULL,
	"OwnerId" uuid NOT NULL,
	"IsDisabled" bool NOT NULL,
	"Fullname" text NULL,
	"Username" text NULL,
	"PasswordHash" text NULL,
	CONSTRAINT "PK_Profiles" PRIMARY KEY ("ID")
);


-- public."Commands" definition

-- Drop table

-- DROP TABLE public."Commands";

CREATE TABLE public."Commands" (
	"ID" uuid NOT NULL,
	"Name" text NULL,
	"Description" text NULL,
	"CreatedOn" timestamp NOT NULL,
	"ModifiedOn" timestamp NOT NULL,
	"DisabledOn" timestamp NULL,
	"CreatedBy" uuid NOT NULL,
	"ModifiedBy" uuid NOT NULL,
	"OwnerId" uuid NOT NULL,
	"IsDisabled" bool NOT NULL,
	"CustomCommand" text NULL,
	"DeviceType" int4 NOT NULL,
	"PredefinedCommandId" uuid NULL,
	"DeviceID" uuid NULL,
	CONSTRAINT "PK_Commands" PRIMARY KEY ("ID"),
	CONSTRAINT "FK_Commands_Devices_DeviceID" FOREIGN KEY ("DeviceID") REFERENCES "Devices"("ID") ON DELETE RESTRICT,
	CONSTRAINT "FK_Commands_PredefinedCommands_PredefinedCommandId" FOREIGN KEY ("PredefinedCommandId") REFERENCES "PredefinedCommands"("ID") ON DELETE RESTRICT
);
CREATE INDEX "IX_Commands_DeviceID" ON public."Commands" USING btree ("DeviceID");
CREATE UNIQUE INDEX "IX_Commands_PredefinedCommandId" ON public."Commands" USING btree ("PredefinedCommandId");


-- public."DeviceCommands" definition

-- Drop table

-- DROP TABLE public."DeviceCommands";

CREATE TABLE public."DeviceCommands" (
	"CommandId" uuid NOT NULL,
	"DeviceId" uuid NOT NULL,
	"ID" uuid NOT NULL,
	"Name" text NULL,
	"Description" text NULL,
	"CreatedOn" timestamp NOT NULL,
	"ModifiedOn" timestamp NOT NULL,
	"DisabledOn" timestamp NULL,
	"CreatedBy" uuid NOT NULL,
	"ModifiedBy" uuid NOT NULL,
	"OwnerId" uuid NOT NULL,
	"IsDisabled" bool NOT NULL,
	"Duration" interval NOT NULL,
	"DeviceType" int4 NOT NULL,
	"PreviousDeviceCommandId" uuid NULL,
	CONSTRAINT "PK_DeviceCommands" PRIMARY KEY ("CommandId", "DeviceId"),
	CONSTRAINT "FK_DeviceCommands_Commands_CommandId" FOREIGN KEY ("CommandId") REFERENCES "Commands"("ID") ON DELETE CASCADE,
	CONSTRAINT "FK_DeviceCommands_Devices_DeviceId" FOREIGN KEY ("DeviceId") REFERENCES "Devices"("ID") ON DELETE CASCADE
);
CREATE INDEX "IX_DeviceCommands_DeviceId" ON public."DeviceCommands" USING btree ("DeviceId");