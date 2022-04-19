-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Apr 14, 2022 alle 09:17
-- Versione del server: 10.4.16-MariaDB
-- Versione PHP: 7.4.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `scuola2122`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `p73e6_immobile`
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
-- Dump dei dati per la tabella `p73e6_immobile`
--

INSERT INTO `p73e6_immobile` (`id`, `nome`, `via`, `civico`, `metratura`, `piano`, `locali`, `idZona`, `idTipologia`) VALUES
(1, 'Locanda Miramare', 'via Del Commercio', 13, 350, 0, 5, 1, 2);

-- --------------------------------------------------------

--
-- Struttura della tabella `p73e6_possiede`
--

CREATE TABLE `p73e6_possiede` (
  `id` int(10) UNSIGNED NOT NULL,
  `data_acquisto` date DEFAULT NULL,
  `idProprietario` int(10) UNSIGNED DEFAULT NULL,
  `idImmobile` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dump dei dati per la tabella `p73e6_possiede`
--

INSERT INTO `p73e6_possiede` (`id`, `data_acquisto`, `idProprietario`, `idImmobile`) VALUES
(1, '2022-04-12', 1, 1);

-- --------------------------------------------------------

--
-- Struttura della tabella `p73e6_proprietario`
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
-- Dump dei dati per la tabella `p73e6_proprietario`
--

INSERT INTO `p73e6_proprietario` (`id`, `cognome`, `nome`, `via`, `civico`, `citta`, `telefono`, `mail`) VALUES
(1, 'PRADELLA', 'FRANCESCO', 'I Maggio', 5, 'San Crispino', '555-54321', 'francesco.pradella@fp.it');

-- --------------------------------------------------------

--
-- Struttura della tabella `p73e6_rendita_annua`
--

CREATE TABLE `p73e6_rendita_annua` (
  `id` int(10) UNSIGNED NOT NULL,
  `anno` int(10) UNSIGNED NOT NULL,
  `prezzo_mq` float DEFAULT NULL,
  `idZona` int(10) UNSIGNED DEFAULT NULL,
  `idTipologia` int(10) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Struttura della tabella `p73e6_tipologia`
--

CREATE TABLE `p73e6_tipologia` (
  `id` int(10) UNSIGNED NOT NULL,
  `nome` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dump dei dati per la tabella `p73e6_tipologia`
--

INSERT INTO `p73e6_tipologia` (`id`, `nome`) VALUES
(1, 'Abitazione'),
(2, 'Negozio'),
(3, 'Ufficio');

-- --------------------------------------------------------

--
-- Struttura della tabella `p73e6_zona`
--

CREATE TABLE `p73e6_zona` (
  `id` int(10) UNSIGNED NOT NULL,
  `nome` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dump dei dati per la tabella `p73e6_zona`
--

INSERT INTO `p73e6_zona` (`id`, `nome`) VALUES
(1, 'Zona 1'),
(2, 'Zona 2'),
(3, 'Zona 3');

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `p73e6_immobile`
--
ALTER TABLE `p73e6_immobile`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idZona` (`idZona`),
  ADD KEY `idTipologia` (`idTipologia`);

--
-- Indici per le tabelle `p73e6_possiede`
--
ALTER TABLE `p73e6_possiede`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idProprietario` (`idProprietario`),
  ADD KEY `idImmobile` (`idImmobile`);

--
-- Indici per le tabelle `p73e6_proprietario`
--
ALTER TABLE `p73e6_proprietario`
  ADD PRIMARY KEY (`id`);

--
-- Indici per le tabelle `p73e6_rendita_annua`
--
ALTER TABLE `p73e6_rendita_annua`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idZona` (`idZona`),
  ADD KEY `idTipologia` (`idTipologia`);

--
-- Indici per le tabelle `p73e6_tipologia`
--
ALTER TABLE `p73e6_tipologia`
  ADD PRIMARY KEY (`id`);

--
-- Indici per le tabelle `p73e6_zona`
--
ALTER TABLE `p73e6_zona`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `p73e6_immobile`
--
ALTER TABLE `p73e6_immobile`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT per la tabella `p73e6_possiede`
--
ALTER TABLE `p73e6_possiede`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT per la tabella `p73e6_proprietario`
--
ALTER TABLE `p73e6_proprietario`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT per la tabella `p73e6_rendita_annua`
--
ALTER TABLE `p73e6_rendita_annua`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `p73e6_tipologia`
--
ALTER TABLE `p73e6_tipologia`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT per la tabella `p73e6_zona`
--
ALTER TABLE `p73e6_zona`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `p73e6_immobile`
--
ALTER TABLE `p73e6_immobile`
  ADD CONSTRAINT `p73e6_immobile_ibfk_1` FOREIGN KEY (`idZona`) REFERENCES `p73e6_zona` (`id`),
  ADD CONSTRAINT `p73e6_immobile_ibfk_2` FOREIGN KEY (`idTipologia`) REFERENCES `p73e6_tipologia` (`id`);

--
-- Limiti per la tabella `p73e6_possiede`
--
ALTER TABLE `p73e6_possiede`
  ADD CONSTRAINT `p73e6_possiede_ibfk_1` FOREIGN KEY (`idProprietario`) REFERENCES `p73e6_proprietario` (`id`),
  ADD CONSTRAINT `p73e6_possiede_ibfk_2` FOREIGN KEY (`idImmobile`) REFERENCES `p73e6_immobile` (`id`);

--
-- Limiti per la tabella `p73e6_rendita_annua`
--
ALTER TABLE `p73e6_rendita_annua`
  ADD CONSTRAINT `p73e6_rendita_annua_ibfk_1` FOREIGN KEY (`idZona`) REFERENCES `p73e6_zona` (`id`),
  ADD CONSTRAINT `p73e6_rendita_annua_ibfk_2` FOREIGN KEY (`idTipologia`) REFERENCES `p73e6_tipologia` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
