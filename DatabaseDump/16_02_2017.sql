-- MySQL dump 10.13  Distrib 5.7.12, for Win64 (x86_64)
--
-- Host: localhost    Database: remoteworkstation
-- ------------------------------------------------------
-- Server version	5.6.33

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `elementconfiguration`
--

DROP TABLE IF EXISTS `elementconfiguration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `elementconfiguration` (
  `idElementConfiguration` int(11) NOT NULL AUTO_INCREMENT,
  `remoteWorkstationID` int(11) DEFAULT NULL,
  `displayName` varchar(255) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `groupName` varchar(255) DEFAULT NULL,
  `function` varchar(255) DEFAULT NULL,
  `elementTypeID` int(11) DEFAULT NULL,
  `tooltip` varchar(255) DEFAULT NULL,
  `remoteViewRelevant` tinyint(1) DEFAULT NULL,
  `pin` smallint(255) DEFAULT NULL,
  `isFeature` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`idElementConfiguration`),
  UNIQUE KEY `idElementConfiguration` (`idElementConfiguration`),
  KEY `remoteWorkstationID` (`remoteWorkstationID`),
  KEY `elementTypeID` (`elementTypeID`),
  CONSTRAINT `elementconfiguration_ibfk_1` FOREIGN KEY (`remoteWorkstationID`) REFERENCES `remoteworkstation` (`idRemoteWorkstation`),
  CONSTRAINT `elementconfiguration_ibfk_2` FOREIGN KEY (`elementTypeID`) REFERENCES `elementtype` (`idElementType`)
) ENGINE=InnoDB AUTO_INCREMENT=53 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `elementconfiguration`
--

LOCK TABLES `elementconfiguration` WRITE;
/*!40000 ALTER TABLE `elementconfiguration` DISABLE KEYS */;
INSERT INTO `elementconfiguration` VALUES (1,NULL,'CAN','CAN','Peripherie','CAN',NULL,NULL,0,255,0),(2,1,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,2,1),(3,1,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(4,1,'MiniCube','MiniCube','Debugger','AC Debugger',1,'AC Debugger (MiniCube)',0,1,1),(5,1,'Lan Debugger','Lan Debugger','Debugger','Lan Debugger',1,'Lan Debugger',0,2,1),(6,1,'Sound','Sound','Additionals','Sound',4,'Sound',0,2,1),(7,1,'LVDS','LVDS','Additionals','LVDS',5,'LVDS',0,5,1),(8,1,'HUD','HUD','Additionals','HUD',6,'HUD',0,5,1),(9,2,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(10,2,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(11,3,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(12,3,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(13,4,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(14,4,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(15,5,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(16,5,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(17,6,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(18,6,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(19,7,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(20,7,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(21,8,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(22,8,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(23,9,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(24,9,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(25,10,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(26,10,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(27,11,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(28,11,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(29,12,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(30,12,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(31,13,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(32,13,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(33,14,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(34,14,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(35,15,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(36,15,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(37,16,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(38,16,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(39,17,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(40,17,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(41,18,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(42,18,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(43,19,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(44,19,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(45,20,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(46,20,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(47,21,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(48,21,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(49,22,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(50,22,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0),(51,23,'CAN','CAN','Peripherie','CAN',1,'HMI CAN',0,255,0),(52,23,'Kl30','Kl30','Peripherie','Kl30',2,'Kl30',0,255,0);
/*!40000 ALTER TABLE `elementconfiguration` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `elementtype`
--

DROP TABLE IF EXISTS `elementtype`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `elementtype` (
  `idElementType` int(11) NOT NULL AUTO_INCREMENT,
  `type` int(11) DEFAULT NULL,
  PRIMARY KEY (`idElementType`),
  UNIQUE KEY `idElementType` (`idElementType`),
  UNIQUE KEY `type` (`type`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `elementtype`
--

LOCK TABLES `elementtype` WRITE;
/*!40000 ALTER TABLE `elementtype` DISABLE KEYS */;
INSERT INTO `elementtype` VALUES (1,0),(2,1),(3,2),(4,3),(6,4),(5,5);
/*!40000 ALTER TABLE `elementtype` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `flashhistory`
--

DROP TABLE IF EXISTS `flashhistory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `flashhistory` (
  `idFlashHistory` int(11) NOT NULL AUTO_INCREMENT,
  `remoteWorkstationID` int(11) DEFAULT NULL,
  `softwareAC` varchar(255) DEFAULT NULL,
  `softwareACToken` varchar(255) DEFAULT NULL,
  `softwareGC` varchar(255) DEFAULT NULL,
  `softwareGCToken` varchar(255) DEFAULT NULL,
  `softwareBootloader` varchar(255) DEFAULT NULL,
  `softwareBootloaderToken` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`idFlashHistory`),
  UNIQUE KEY `idFlashHistory` (`idFlashHistory`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `flashhistory`
--

LOCK TABLES `flashhistory` WRITE;
/*!40000 ALTER TABLE `flashhistory` DISABLE KEYS */;
/*!40000 ALTER TABLE `flashhistory` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `generalsettings`
--

DROP TABLE IF EXISTS `generalsettings`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `generalsettings` (
  `idGeneralSettings` int(11) NOT NULL AUTO_INCREMENT,
  `shutdownTime` datetime DEFAULT NULL,
  `logoutTime` datetime DEFAULT NULL,
  PRIMARY KEY (`idGeneralSettings`),
  UNIQUE KEY `idGeneralSettings` (`idGeneralSettings`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `generalsettings`
--

LOCK TABLES `generalsettings` WRITE;
/*!40000 ALTER TABLE `generalsettings` DISABLE KEYS */;
/*!40000 ALTER TABLE `generalsettings` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `instruction`
--

DROP TABLE IF EXISTS `instruction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `instruction` (
  `idInstruction` int(11) NOT NULL AUTO_INCREMENT,
  `step` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`idInstruction`),
  UNIQUE KEY `idInstruction` (`idInstruction`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `instruction`
--

LOCK TABLES `instruction` WRITE;
/*!40000 ALTER TABLE `instruction` DISABLE KEYS */;
/*!40000 ALTER TABLE `instruction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `log`
--

DROP TABLE IF EXISTS `log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `log` (
  `idLog` int(11) NOT NULL AUTO_INCREMENT,
  `message` varchar(255) DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `loglevel` varchar(255) DEFAULT NULL,
  `threadId` bigint(20) DEFAULT NULL,
  `errorID` int(11) DEFAULT NULL,
  `type` varchar(255) DEFAULT NULL,
  `computerName` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`idLog`),
  UNIQUE KEY `idLog` (`idLog`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `log`
--

LOCK TABLES `log` WRITE;
/*!40000 ALTER TABLE `log` DISABLE KEYS */;
/*!40000 ALTER TABLE `log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `product`
--

DROP TABLE IF EXISTS `product`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `product` (
  `idProduct` int(11) NOT NULL AUTO_INCREMENT,
  `productName` varchar(255) DEFAULT NULL,
  `part` varchar(255) DEFAULT NULL,
  `receptID` int(11) DEFAULT NULL,
  PRIMARY KEY (`idProduct`),
  UNIQUE KEY `idProduct` (`idProduct`),
  KEY `receptID` (`receptID`),
  CONSTRAINT `product_ibfk_1` FOREIGN KEY (`receptID`) REFERENCES `recept` (`idRecept`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `product`
--

LOCK TABLES `product` WRITE;
/*!40000 ALTER TABLE `product` DISABLE KEYS */;
/*!40000 ALTER TABLE `product` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `project`
--

DROP TABLE IF EXISTS `project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `project` (
  `idProject` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`idProject`),
  UNIQUE KEY `idProject` (`idProject`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `project`
--

LOCK TABLES `project` WRITE;
/*!40000 ALTER TABLE `project` DISABLE KEYS */;
INSERT INTO `project` VALUES (12,'BR205IC'),(4,'BR213IC-EL-MY16'),(5,'BR213IC-EL-MY17'),(6,'BR213IC-EL-MY18'),(7,'BR213IC-EL205MY18'),(1,'BR213IC-HL-MY16'),(2,'BR213IC-HL-MY17'),(3,'BR213IC-HL-MY18'),(13,'BR222IC'),(14,'BR447IC'),(8,'BR463IC-EL-MY17'),(9,'BR463IC-HL-MY17'),(15,'BR470IC'),(10,'VS30IC_SW-HL'),(11,'VS30IC_SW-LL/ML');
/*!40000 ALTER TABLE `project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `recept`
--

DROP TABLE IF EXISTS `recept`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `recept` (
  `idRecept` int(11) NOT NULL AUTO_INCREMENT,
  `receptName` varchar(255) DEFAULT NULL,
  `orderNumber` int(11) DEFAULT NULL,
  `instructionID` int(11) DEFAULT NULL,
  PRIMARY KEY (`idRecept`),
  UNIQUE KEY `idRecept` (`idRecept`),
  KEY `instructionID` (`instructionID`),
  CONSTRAINT `recept_ibfk_1` FOREIGN KEY (`instructionID`) REFERENCES `instruction` (`idInstruction`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `recept`
--

LOCK TABLES `recept` WRITE;
/*!40000 ALTER TABLE `recept` DISABLE KEYS */;
/*!40000 ALTER TABLE `recept` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `remoteworkstation`
--

DROP TABLE IF EXISTS `remoteworkstation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `remoteworkstation` (
  `idRemoteWorkstation` int(11) NOT NULL AUTO_INCREMENT,
  `userID` int(11) DEFAULT NULL,
  `projectID` int(11) DEFAULT NULL,
  `hostname` varchar(255) DEFAULT NULL,
  `mac` varchar(255) DEFAULT NULL,
  `ip` varchar(15) DEFAULT NULL,
  `powerstripeIp` varchar(15) DEFAULT NULL,
  `powerstripeId` varchar(5) DEFAULT NULL,
  `remoteboxComPort` tinyint(2) unsigned DEFAULT NULL,
  `remoteboxHwId` varchar(255) DEFAULT NULL,
  `remoteboxSwVersion` varchar(255) DEFAULT NULL,
  `state` int(2) DEFAULT NULL,
  PRIMARY KEY (`idRemoteWorkstation`),
  UNIQUE KEY `idRemoteWorkstation` (`idRemoteWorkstation`),
  UNIQUE KEY `hostname` (`hostname`),
  KEY `userID` (`userID`),
  KEY `projectID` (`projectID`),
  CONSTRAINT `remoteworkstation_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `user` (`idUser`),
  CONSTRAINT `remoteworkstation_ibfk_2` FOREIGN KEY (`projectID`) REFERENCES `project` (`idProject`)
) ENGINE=InnoDB AUTO_INCREMENT=24 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `remoteworkstation`
--

LOCK TABLES `remoteworkstation` WRITE;
/*!40000 ALTER TABLE `remoteworkstation` DISABLE KEYS */;
INSERT INTO `remoteworkstation` VALUES (1,NULL,3,'A821','00-50-56-C0-00-08','192.168.111.245','192.168.111.242','A213',16,'asfajkaljk','asdjhak',1),(2,NULL,2,'A684','00-50-56-C0-00-09','192.168.111.246','192.168.111.249','A217',16,'abcdef','abcdef',1),(3,NULL,3,'A843','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',3),(4,NULL,2,'A820','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',0),(5,NULL,2,'A823','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',2),(6,NULL,2,'A795','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(7,NULL,1,'A822','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(8,NULL,3,'A856','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(9,NULL,3,'A864','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(10,NULL,3,'A860','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',0),(11,NULL,3,'A859','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',3),(12,NULL,3,'A911','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',0),(13,NULL,7,'A798','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',2),(14,NULL,7,'A841','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(15,NULL,5,'A772','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(16,NULL,5,'A796','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(17,NULL,5,'A855','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(18,NULL,11,'A799','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(19,NULL,11,'A842','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(20,NULL,11,'A865','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(21,NULL,10,'A857','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(22,NULL,10,'A797','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1),(23,NULL,10,'A910','00-50-56-C0-00-11','192.168.111.142','192.168.111.139','A224',16,'abcdef','abcdef',1);
/*!40000 ALTER TABLE `remoteworkstation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `idUser` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `mksUsername` varchar(50) DEFAULT NULL,
  `mksPassword` varchar(255) DEFAULT NULL,
  `initials` varchar(255) DEFAULT NULL,
  `notifiyRemoteDesktop` tinyint(1) DEFAULT NULL,
  `notifiyDesktop` tinyint(1) DEFAULT NULL,
  `role` tinyint(2) DEFAULT NULL,
  PRIMARY KEY (`idUser`),
  UNIQUE KEY `idUser` (`idUser`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'Kunadt','Schleissheimer','uidw5301','Windows2002','IvKu',1,1,2);
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-02-16 18:42:26
