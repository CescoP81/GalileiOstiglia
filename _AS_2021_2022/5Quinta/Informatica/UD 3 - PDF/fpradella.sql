-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Creato il: Gen 14, 2022 alle 09:00
-- Versione del server: 5.7.34-0ubuntu0.18.04.1
-- Versione PHP: 7.2.24-0ubuntu0.18.04.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `fpradella`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `p62e1_Cliente`
--

CREATE TABLE `p62e1_Cliente` (
  `Id` int(10) UNSIGNED NOT NULL,
  `RagioneSociale` varchar(30) NOT NULL,
  `indirizzo` varchar(50) NOT NULL,
  `numTelefono` varchar(10) NOT NULL,
  `PartitaIva` char(10) DEFAULT NULL,
  `idAgente` int(11) DEFAULT NULL,
  `Fido` int(11) DEFAULT NULL,
  `idLocalita` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dump dei dati per la tabella `p62e1_Cliente`
--

INSERT INTO `p62e1_Cliente` (`Id`, `RagioneSociale`, `indirizzo`, `numTelefono`, `PartitaIva`, `idAgente`, `Fido`, `idLocalita`) VALUES
(1, 'Pradella Francesco', 'via Roma, 5', '3558965723', '', 125, 2000, 2),
(2, 'Grossi Filippo', 'via Schiappa, 13', '3558965756', '', 125, 1500, 7),
(3, 'Menghini Arianna', 'via Baracca, 20', '3898965723', '', 100, 2250, 6),
(4, 'Besutti Matteo', 'via Arisca, 21', '3896325723', '', 100, 1000, 3),
(5, 'Hasmi Muqeet Ali', 'via Sociale, 12', '4568965723', '', 100, 1700, 4),
(6, 'Schiattarella Giorgia', 'via Lungomare, 7', '3338965723', '', 250, 2500, 1);

-- --------------------------------------------------------

--
-- Struttura della tabella `p62e1_Localita`
--

CREATE TABLE `p62e1_Localita` (
  `Id` int(10) UNSIGNED NOT NULL,
  `Cap` char(5) NOT NULL,
  `Nome` varchar(30) NOT NULL,
  `Prov` char(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dump dei dati per la tabella `p62e1_Localita`
--

INSERT INTO `p62e1_Localita` (`Id`, `Cap`, `Nome`, `Prov`) VALUES
(1, '46035', 'Ostiglia', 'MN'),
(2, '46020', 'Quingentole', 'MN'),
(3, '46026', 'Quistello', 'MN'),
(4, '46027', 'San Benedetto Po', 'MN'),
(5, '46036', 'Revere', 'MN'),
(6, '46028', 'Sermide', 'MN'),
(7, '46020', 'Magnacavallo', 'MN');

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `p62e1_Cliente`
--
ALTER TABLE `p62e1_Cliente`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `idLocalita` (`idLocalita`);

--
-- Indici per le tabelle `p62e1_Localita`
--
ALTER TABLE `p62e1_Localita`
  ADD PRIMARY KEY (`Id`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `p62e1_Cliente`
--
ALTER TABLE `p62e1_Cliente`
  MODIFY `Id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT per la tabella `p62e1_Localita`
--
ALTER TABLE `p62e1_Localita`
  MODIFY `Id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `p62e1_Cliente`
--
ALTER TABLE `p62e1_Cliente`
  ADD CONSTRAINT `p62e1_Cliente_ibfk_1` FOREIGN KEY (`idLocalita`) REFERENCES `p62e1_Localita` (`Id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
