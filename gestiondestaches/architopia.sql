--------------------------------------------------------
--  Fichier créé - mercredi-mars-12-2025   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Sequence ARCHITECTE_SEQ
--------------------------------------------------------

   CREATE SEQUENCE  "F3DDI"."ARCHITECTE_SEQ"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE
--------------------------------------------------------
--  DDL for Sequence CLIENT_SEQ
--------------------------------------------------------

   CREATE SEQUENCE  "F3DDI"."CLIENT_SEQ"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE
--------------------------------------------------------
--  DDL for Sequence FORMATION_SEQ
--------------------------------------------------------

   CREATE SEQUENCE  "F3DDI"."FORMATION_SEQ"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE
--------------------------------------------------------
--  DDL for Sequence PROJET_SEQ
--------------------------------------------------------

   CREATE SEQUENCE  "F3DDI"."PROJET_SEQ"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE
--------------------------------------------------------
--  DDL for Sequence TACHE_SEQ
--------------------------------------------------------

   CREATE SEQUENCE  "F3DDI"."TACHE_SEQ"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE
--------------------------------------------------------
--  DDL for Table ARCHITECTE
--------------------------------------------------------

  CREATE TABLE "F3DDI"."ARCHITECTE" 
   (	"ID_ARCHITECTE" NUMBER(10,0), 
	"NOM" VARCHAR2(100) NOT NULL ENABLE, 
	"COURRIEL" VARCHAR2(100) NOT NULL ENABLE, 
	"ROLE" VARCHAR2(20) NOT NULL ENABLE, 
	"MOT_DE_PASSE" VARCHAR2(255) NOT NULL ENABLE, 
	"SECURITY_QUESTION" VARCHAR2(255) NOT NULL ENABLE, 
	"SECURITY_ANSWER" VARCHAR2(255) NOT NULL ENABLE, 
	 PRIMARY KEY ("ID_ARCHITECTE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE, 
	 UNIQUE ("COURRIEL")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"
--------------------------------------------------------
--  DDL for Table CLIENT
--------------------------------------------------------

  CREATE TABLE "F3DDI"."CLIENT" 
   (	"ID_CLIENT" NUMBER(10,0), 
	"NOM" VARCHAR2(100) NOT NULL ENABLE, 
	"PRENOM" VARCHAR2(100) NOT NULL ENABLE, 
	"EMAIL" VARCHAR2(100) NOT NULL ENABLE, 
	"NUM_TLF" VARCHAR2(20) NOT NULL ENABLE, 
	"NB_PROJET" NUMBER(5,0) NOT NULL ENABLE, 
	 PRIMARY KEY ("ID_CLIENT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE, 
	 UNIQUE ("EMAIL")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"
--------------------------------------------------------
--  DDL for Table FORMATION
--------------------------------------------------------

  CREATE TABLE "F3DDI"."FORMATION" 
   (	"ID_FORMATION" NUMBER(10,0), 
	"DATEDEBUT" DATE NOT NULL ENABLE, 
	"DATEFIN" DATE NOT NULL ENABLE, 
	"FORMATEUR" VARCHAR2(100) NOT NULL ENABLE, 
	"LIEU" VARCHAR2(255) NOT NULL ENABLE, 
	"PRIX" NUMBER(10,2) NOT NULL ENABLE, 
	 PRIMARY KEY ("ID_FORMATION")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"
--------------------------------------------------------
--  DDL for Table PROJET
--------------------------------------------------------

  CREATE TABLE "F3DDI"."PROJET" 
   (	"ID_PROJET" NUMBER(10,0), 
	"NOM_PROJET" VARCHAR2(255) NOT NULL ENABLE, 
	"DATE_DEBUT" DATE NOT NULL ENABLE, 
	"DATE_FIN" DATE NOT NULL ENABLE, 
	"STATUT" VARCHAR2(20) NOT NULL ENABLE, 
	"DESCRIPTION" CLOB, 
	 PRIMARY KEY ("ID_PROJET")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" 
 LOB ("DESCRIPTION") STORE AS BASICFILE (
  TABLESPACE "SYSTEM" ENABLE STORAGE IN ROW CHUNK 8192 RETENTION 
  NOCACHE LOGGING 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT))
--------------------------------------------------------
--  DDL for Table TACHE
--------------------------------------------------------

  CREATE TABLE "F3DDI"."TACHE" 
   (	"ID_TACHE" NUMBER(10,0), 
	"DATEDEB" DATE NOT NULL ENABLE, 
	"DATEFIN" DATE NOT NULL ENABLE, 
	"MISSION" VARCHAR2(255) NOT NULL ENABLE, 
	"STATUT" VARCHAR2(20) NOT NULL ENABLE, 
	"DESCRIPTION" CLOB, 
	 PRIMARY KEY ("ID_TACHE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" 
 LOB ("DESCRIPTION") STORE AS BASICFILE (
  TABLESPACE "SYSTEM" ENABLE STORAGE IN ROW CHUNK 8192 RETENTION 
  NOCACHE LOGGING 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT))
REM INSERTING into F3DDI.ARCHITECTE
SET DEFINE OFF;
REM INSERTING into F3DDI.CLIENT
SET DEFINE OFF;
REM INSERTING into F3DDI.FORMATION
SET DEFINE OFF;
REM INSERTING into F3DDI.PROJET
SET DEFINE OFF;
REM INSERTING into F3DDI.TACHE
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Trigger ARCHITECTE_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."ARCHITECTE_TRIGGER" 
BEFORE INSERT ON Architecte 
FOR EACH ROW 
BEGIN 
    SELECT architecte_seq.NEXTVAL INTO :NEW.Id_architecte FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."ARCHITECTE_TRIGGER" ENABLE
--------------------------------------------------------
--  DDL for Trigger CLIENT_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."CLIENT_TRIGGER" 
BEFORE INSERT ON Client 
FOR EACH ROW 
BEGIN 
    SELECT client_seq.NEXTVAL INTO :NEW.Id_client FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."CLIENT_TRIGGER" ENABLE
--------------------------------------------------------
--  DDL for Trigger FORMATION_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."FORMATION_TRIGGER" 
BEFORE INSERT ON Formation 
FOR EACH ROW 
BEGIN 
    SELECT formation_seq.NEXTVAL INTO :NEW.Id_formation FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."FORMATION_TRIGGER" ENABLE
--------------------------------------------------------
--  DDL for Trigger PROJET_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."PROJET_TRIGGER" 
BEFORE INSERT ON Projet 
FOR EACH ROW 
BEGIN 
    SELECT projet_seq.NEXTVAL INTO :NEW.Id_projet FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."PROJET_TRIGGER" ENABLE
--------------------------------------------------------
--  DDL for Trigger TACHE_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."TACHE_TRIGGER" 
BEFORE INSERT ON Tache 
FOR EACH ROW 
BEGIN 
    SELECT tache_seq.NEXTVAL INTO :NEW.Id_tache FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."TACHE_TRIGGER" ENABLE
--------------------------------------------------------
--  Constraints for Table PROJET
--------------------------------------------------------

  ALTER TABLE "F3DDI"."PROJET" ADD PRIMARY KEY ("ID_PROJET")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."PROJET" MODIFY ("STATUT" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."PROJET" MODIFY ("DATE_FIN" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."PROJET" MODIFY ("DATE_DEBUT" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."PROJET" MODIFY ("NOM_PROJET" NOT NULL ENABLE)
--------------------------------------------------------
--  Constraints for Table CLIENT
--------------------------------------------------------

  ALTER TABLE "F3DDI"."CLIENT" ADD UNIQUE ("EMAIL")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."CLIENT" ADD PRIMARY KEY ("ID_CLIENT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("NB_PROJET" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("NUM_TLF" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("EMAIL" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("PRENOM" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("NOM" NOT NULL ENABLE)
--------------------------------------------------------
--  Constraints for Table ARCHITECTE
--------------------------------------------------------

  ALTER TABLE "F3DDI"."ARCHITECTE" ADD UNIQUE ("COURRIEL")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."ARCHITECTE" ADD PRIMARY KEY ("ID_ARCHITECTE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("SECURITY_ANSWER" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("SECURITY_QUESTION" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("MOT_DE_PASSE" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("ROLE" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("COURRIEL" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("NOM" NOT NULL ENABLE)
--------------------------------------------------------
--  Constraints for Table FORMATION
--------------------------------------------------------

  ALTER TABLE "F3DDI"."FORMATION" ADD PRIMARY KEY ("ID_FORMATION")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("PRIX" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("LIEU" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("FORMATEUR" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("DATEFIN" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("DATEDEBUT" NOT NULL ENABLE)
--------------------------------------------------------
--  Constraints for Table TACHE
--------------------------------------------------------

  ALTER TABLE "F3DDI"."TACHE" ADD PRIMARY KEY ("ID_TACHE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."TACHE" MODIFY ("STATUT" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."TACHE" MODIFY ("MISSION" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."TACHE" MODIFY ("DATEFIN" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."TACHE" MODIFY ("DATEDEB" NOT NULL ENABLE)
ALTER TRIGGER "F3DDI"."ARCHITECTE_TRIGGER" ENABLE
--------------------------------------------------------
--  DDL for Trigger CLIENT_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."CLIENT_TRIGGER" 
BEFORE INSERT ON Client 
FOR EACH ROW 
BEGIN 
    SELECT client_seq.NEXTVAL INTO :NEW.Id_client FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."CLIENT_TRIGGER" ENABLE
--------------------------------------------------------
--  DDL for Trigger FORMATION_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."FORMATION_TRIGGER" 
BEFORE INSERT ON Formation 
FOR EACH ROW 
BEGIN 
    SELECT formation_seq.NEXTVAL INTO :NEW.Id_formation FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."FORMATION_TRIGGER" ENABLE
--------------------------------------------------------
--  DDL for Trigger PROJET_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."PROJET_TRIGGER" 
BEFORE INSERT ON Projet 
FOR EACH ROW 
BEGIN 
    SELECT projet_seq.NEXTVAL INTO :NEW.Id_projet FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."PROJET_TRIGGER" ENABLE
--------------------------------------------------------
--  DDL for Trigger TACHE_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "F3DDI"."TACHE_TRIGGER" 
BEFORE INSERT ON Tache 
FOR EACH ROW 
BEGIN 
    SELECT tache_seq.NEXTVAL INTO :NEW.Id_tache FROM DUAL;
END;

ALTER TRIGGER "F3DDI"."TACHE_TRIGGER" ENABLE
--------------------------------------------------------
--  Constraints for Table PROJET
--------------------------------------------------------

  ALTER TABLE "F3DDI"."PROJET" ADD PRIMARY KEY ("ID_PROJET")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."PROJET" MODIFY ("STATUT" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."PROJET" MODIFY ("DATE_FIN" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."PROJET" MODIFY ("DATE_DEBUT" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."PROJET" MODIFY ("NOM_PROJET" NOT NULL ENABLE)
--------------------------------------------------------
--  Constraints for Table CLIENT
--------------------------------------------------------

  ALTER TABLE "F3DDI"."CLIENT" ADD UNIQUE ("EMAIL")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."CLIENT" ADD PRIMARY KEY ("ID_CLIENT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("NB_PROJET" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("NUM_TLF" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("EMAIL" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("PRENOM" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."CLIENT" MODIFY ("NOM" NOT NULL ENABLE)
--------------------------------------------------------
--  Constraints for Table ARCHITECTE
--------------------------------------------------------

  ALTER TABLE "F3DDI"."ARCHITECTE" ADD UNIQUE ("COURRIEL")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."ARCHITECTE" ADD PRIMARY KEY ("ID_ARCHITECTE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("SECURITY_ANSWER" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("SECURITY_QUESTION" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("MOT_DE_PASSE" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("ROLE" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("COURRIEL" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."ARCHITECTE" MODIFY ("NOM" NOT NULL ENABLE)
--------------------------------------------------------
--  Constraints for Table FORMATION
--------------------------------------------------------

  ALTER TABLE "F3DDI"."FORMATION" ADD PRIMARY KEY ("ID_FORMATION")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("PRIX" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("LIEU" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("FORMATEUR" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("DATEFIN" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."FORMATION" MODIFY ("DATEDEBUT" NOT NULL ENABLE)
--------------------------------------------------------
--  Constraints for Table TACHE
--------------------------------------------------------

  ALTER TABLE "F3DDI"."TACHE" ADD PRIMARY KEY ("ID_TACHE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE
  ALTER TABLE "F3DDI"."TACHE" MODIFY ("STATUT" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."TACHE" MODIFY ("MISSION" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."TACHE" MODIFY ("DATEFIN" NOT NULL ENABLE)
  ALTER TABLE "F3DDI"."TACHE" MODIFY ("DATEDEB" NOT NULL ENABLE)
