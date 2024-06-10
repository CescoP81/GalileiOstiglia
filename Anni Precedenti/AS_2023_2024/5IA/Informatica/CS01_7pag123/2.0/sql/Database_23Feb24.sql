-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Creato il: Feb 13, 2024 alle 10:15
-- Versione del server: 5.7.36
-- Versione PHP: 7.4.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `scuola2324`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `citta`
--

DROP TABLE IF EXISTS `citta`;
CREATE TABLE IF NOT EXISTS `citta` (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `nomeCitta` varchar(20) COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dump dei dati per la tabella `citta`
--

INSERT INTO `citta` (`id`, `nomeCitta`) VALUES
(1, 'Mantova'),
(2, 'Verona'),
(3, 'Bologna'),
(4, 'Trento'),
(5, 'Vicenza'),
(6, 'Treviso'),
(7, 'Firenze');

-- --------------------------------------------------------

--
-- Struttura della tabella `dipendente`
--

DROP TABLE IF EXISTS `dipendente`;
CREATE TABLE IF NOT EXISTS `dipendente` (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `Cognome` varchar(30) COLLATE utf8_bin DEFAULT NULL,
  `Nome` varchar(30) COLLATE utf8_bin DEFAULT NULL,
  `idReparto` int(10) UNSIGNED DEFAULT NULL,
  `idCittaResidenza` int(10) UNSIGNED DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `idReparto` (`idReparto`),
  KEY `idCittaResidenza` (`idCittaResidenza`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dump dei dati per la tabella `dipendente`
--

INSERT INTO `dipendente` (`id`, `Cognome`, `Nome`, `idReparto`, `idCittaResidenza`) VALUES
(3, 'Galotta', 'Michela', 6, 1),
(4, 'Rossi', 'Mario', 6, 4),
(5, 'Verdi', 'Mario', 9, 4),
(6, 'Bianchi', 'Mariaelena', 7, 3),
(7, 'Rossi', 'Luigi', 8, 3);

-- --------------------------------------------------------

--
-- Struttura della tabella `pagamento`
--

DROP TABLE IF EXISTS `pagamento`;
CREATE TABLE IF NOT EXISTS `pagamento` (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `data` date DEFAULT NULL,
  `causale` varchar(255) COLLATE utf8_bin DEFAULT NULL,
  `importo` float DEFAULT NULL,
  `idDipendente` int(10) UNSIGNED DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `idDipendente` (`idDipendente`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dump dei dati per la tabella `pagamento`
--

INSERT INTO `pagamento` (`id`, `data`, `causale`, `importo`, `idDipendente`) VALUES
(1, '2024-01-23', 'Stipendio mese di Gennaio', 1250, 3),
(2, '2024-01-23', 'Stipendio mese di Gennaio', 1250, 4),
(3, '2024-01-23', 'Stipendio mese di Gennaio', 1250, 5),
(4, '2024-01-23', 'Stipendio mese di Gennaio', 1250, 6),
(5, '2024-01-23', 'Stipendio mese di Gennaio', 1100, 7),
(7, '2024-02-23', 'Stipendio mese di Gennaio', 1250, 3),
(8, '2024-02-23', 'Stipendio mese di Gennaio', 1250, 4),
(9, '2024-02-23', 'Stipendio mese di Gennaio', 1250, 5),
(10, '2024-02-23', 'Stipendio mese di Gennaio', 1250, 6),
(11, '2024-02-23', 'Stipendio mese di Gennaio', 1100, 7),
(13, '2024-02-25', 'Rimborso viaggio estero', 500, 3),
(14, '2024-02-23', 'Ferie non godute', 1500, 4),
(15, '2024-02-23', 'Straordinari mese di gennaio', 750, 5);

-- --------------------------------------------------------

--
-- Struttura della tabella `reparto`
--

DROP TABLE IF EXISTS `reparto`;
CREATE TABLE IF NOT EXISTS `reparto` (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `nomeReparto` varchar(20) COLLATE utf8_bin DEFAULT NULL,
  `idCittaReparto` int(10) UNSIGNED DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `idCittaReparto` (`idCittaReparto`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dump dei dati per la tabella `reparto`
--

INSERT INTO `reparto` (`id`, `nomeReparto`, `idCittaReparto`) VALUES
(6, 'Manutenzione Caldaie', 1),
(7, 'Vendita Tubi', 7),
(8, 'Caldaie', 3),
(9, 'Caldaie', 6),
(10, 'Bruciatori', 1);

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `dipendente`
--
ALTER TABLE `dipendente`
  ADD CONSTRAINT `dipendente_ibfk_1` FOREIGN KEY (`idReparto`) REFERENCES `reparto` (`id`),
  ADD CONSTRAINT `dipendente_ibfk_2` FOREIGN KEY (`idCittaResidenza`) REFERENCES `citta` (`id`);

--
-- Limiti per la tabella `pagamento`
--
ALTER TABLE `pagamento`
  ADD CONSTRAINT `pagamento_ibfk_1` FOREIGN KEY (`idDipendente`) REFERENCES `dipendente` (`id`);

--
-- Limiti per la tabella `reparto`
--
ALTER TABLE `reparto`
  ADD CONSTRAINT `reparto_ibfk_1` FOREIGN KEY (`idCittaReparto`) REFERENCES `citta` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
