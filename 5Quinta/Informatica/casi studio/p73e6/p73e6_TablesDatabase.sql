-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Apr 19, 2022 at 10:25 PM
-- Server version: 10.1.37-MariaDB
-- PHP Version: 7.3.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `scuola`
--

-- --------------------------------------------------------

--
-- Table structure for table `p73e6_immobile`
--

CREATE TABLE `p73e6_immobile` (
  `id` int(10) UNSIGNED NOT NULL,
  `nome` varchar(20) DEFAULT NULL,
  `via` varchar(30) DEFAULT NULL,
  `civico` tinyint(4) DEFAULT NULL,
  `metratura` int(11) DEFAULT NULL,
  `piano` tinyint(4) DEFAULT NULL,
  `locali` tinyint(4) DEFAULT NULL,
  `idZona` int(10) UNSIGNED DEFAULT NULL,
  `idTipologia` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `p73e6_immobile`
--

INSERT INTO `p73e6_immobile` (`id`, `nome`, `via`, `civico`, `metratura`, `piano`, `locali`, `idZona`, `idTipologia`) VALUES
(1, 'Locanda Miramare', 'via Del Commercio', 13, 350, 0, 5, 1, 2);

-- --------------------------------------------------------

--
-- Table structure for table `p73e6_possiede`
--

CREATE TABLE `p73e6_possiede` (
  `id` int(10) UNSIGNED NOT NULL,
  `data_acquisto` date DEFAULT NULL,
  `idProprietario` int(10) UNSIGNED DEFAULT NULL,
  `idImmobile` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `p73e6_possiede`
--

INSERT INTO `p73e6_possiede` (`id`, `data_acquisto`, `idProprietario`, `idImmobile`) VALUES
(1, '2022-04-12', 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `p73e6_proprietario`
--

CREATE TABLE `p73e6_proprietario` (
  `id` int(10) UNSIGNED NOT NULL,
  `cognome` varchar(20) NOT NULL,
  `nome` varchar(20) NOT NULL,
  `via` varchar(30) DEFAULT NULL,
  `civico` tinyint(4) DEFAULT NULL,
  `citta` varchar(30) DEFAULT NULL,
  `telefono` varchar(15) DEFAULT NULL,
  `mail` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `p73e6_proprietario`
--

INSERT INTO `p73e6_proprietario` (`id`, `cognome`, `nome`, `via`, `civico`, `citta`, `telefono`, `mail`) VALUES
(1, 'PRADELLA', 'FRANCESCO', 'I Maggio', 5, 'San Crispino', '555-54321', 'francesco.pradella@fp.it');

-- --------------------------------------------------------

--
-- Table structure for table `p73e6_rendita_annua`
--

CREATE TABLE `p73e6_rendita_annua` (
  `id` int(10) UNSIGNED NOT NULL,
  `anno` int(10) UNSIGNED NOT NULL,
  `prezzo_mq` float DEFAULT NULL,
  `idZona` int(10) UNSIGNED DEFAULT NULL,
  `idTipologia` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `p73e6_rendita_annua`
--

INSERT INTO `p73e6_rendita_annua` (`id`, `anno`, `prezzo_mq`, `idZona`, `idTipologia`) VALUES
(1, 2022, 1.5, 1, 1),
(2, 2022, 2.75, 1, 2),
(3, 2022, 2.85, 1, 3),
(4, 2022, 1.25, 2, 1),
(5, 2022, 2, 2, 2),
(6, 2022, 2.25, 2, 3),
(7, 2022, 1, 3, 1),
(8, 2022, 0.85, 3, 2),
(9, 2022, 2.15, 3, 3);

-- --------------------------------------------------------

--
-- Table structure for table `p73e6_tipologia`
--

CREATE TABLE `p73e6_tipologia` (
  `id` int(10) UNSIGNED NOT NULL,
  `nome` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `p73e6_tipologia`
--

INSERT INTO `p73e6_tipologia` (`id`, `nome`) VALUES
(1, 'Abitazione'),
(2, 'Negozio'),
(3, 'Ufficio');

-- --------------------------------------------------------

--
-- Table structure for table `p73e6_zona`
--

CREATE TABLE `p73e6_zona` (
  `id` int(10) UNSIGNED NOT NULL,
  `nome` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `p73e6_zona`
--

INSERT INTO `p73e6_zona` (`id`, `nome`) VALUES
(1, 'Zona 1'),
(2, 'Zona 2'),
(3, 'Zona 3');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `p73e6_immobile`
--
ALTER TABLE `p73e6_immobile`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idZona` (`idZona`),
  ADD KEY `idTipologia` (`idTipologia`);

--
-- Indexes for table `p73e6_possiede`
--
ALTER TABLE `p73e6_possiede`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idProprietario` (`idProprietario`),
  ADD KEY `idImmobile` (`idImmobile`);

--
-- Indexes for table `p73e6_proprietario`
--
ALTER TABLE `p73e6_proprietario`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `p73e6_rendita_annua`
--
ALTER TABLE `p73e6_rendita_annua`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idZona` (`idZona`),
  ADD KEY `idTipologia` (`idTipologia`);

--
-- Indexes for table `p73e6_tipologia`
--
ALTER TABLE `p73e6_tipologia`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `p73e6_zona`
--
ALTER TABLE `p73e6_zona`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `p73e6_immobile`
--
ALTER TABLE `p73e6_immobile`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `p73e6_possiede`
--
ALTER TABLE `p73e6_possiede`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `p73e6_proprietario`
--
ALTER TABLE `p73e6_proprietario`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `p73e6_rendita_annua`
--
ALTER TABLE `p73e6_rendita_annua`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `p73e6_tipologia`
--
ALTER TABLE `p73e6_tipologia`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `p73e6_zona`
--
ALTER TABLE `p73e6_zona`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `p73e6_immobile`
--
ALTER TABLE `p73e6_immobile`
  ADD CONSTRAINT `p73e6_immobile_ibfk_1` FOREIGN KEY (`idZona`) REFERENCES `p73e6_zona` (`id`),
  ADD CONSTRAINT `p73e6_immobile_ibfk_2` FOREIGN KEY (`idTipologia`) REFERENCES `p73e6_tipologia` (`id`);

--
-- Constraints for table `p73e6_possiede`
--
ALTER TABLE `p73e6_possiede`
  ADD CONSTRAINT `p73e6_possiede_ibfk_1` FOREIGN KEY (`idProprietario`) REFERENCES `p73e6_proprietario` (`id`),
  ADD CONSTRAINT `p73e6_possiede_ibfk_2` FOREIGN KEY (`idImmobile`) REFERENCES `p73e6_immobile` (`id`);

--
-- Constraints for table `p73e6_rendita_annua`
--
ALTER TABLE `p73e6_rendita_annua`
  ADD CONSTRAINT `p73e6_rendita_annua_ibfk_1` FOREIGN KEY (`idZona`) REFERENCES `p73e6_zona` (`id`),
  ADD CONSTRAINT `p73e6_rendita_annua_ibfk_2` FOREIGN KEY (`idTipologia`) REFERENCES `p73e6_tipologia` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
