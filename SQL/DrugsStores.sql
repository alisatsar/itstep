USE [DB_network_pharmacies]
GO
/****** Object:  Table [dbo].[AllDrugStores]    Script Date: 27.11.2017 1:02:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AllDrugStores](
	[IdDrugStore] [int] NOT NULL,
	[IdDrug] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Drug]    Script Date: 27.11.2017 1:02:24 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Drug](
	[Name] [nvarchar](50) NOT NULL,
	[Cost] [decimal](18, 0) NOT NULL,
	[ProductionDate] [date] NOT NULL,
	[DateExpiryDate] [date] NOT NULL,
	[DrugId] [int] IDENTITY(1,1) NOT NULL,
 CONSTRAINT [PK_Drug_DrugId] PRIMARY KEY CLUSTERED 
(
	[DrugId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
 CONSTRAINT [DF_Drug_Name_Unique] UNIQUE NONCLUSTERED 
(
	[Name] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[DrugStore]    Script Date: 27.11.2017 1:02:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DrugStore](
	[IdDrugStore] [int] IDENTITY(1,1) NOT NULL,
	[City] [nvarchar](50) NOT NULL,
	[Street] [nvarchar](80) NOT NULL,
	[House] [int] NOT NULL,
 CONSTRAINT [PK_DrugStore_IdDrugStore] PRIMARY KEY CLUSTERED 
(
	[IdDrugStore] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[AllDrugStores]  WITH CHECK ADD  CONSTRAINT [FK_Drug_DrugId] FOREIGN KEY([IdDrugStore])
REFERENCES [dbo].[DrugStore] ([IdDrugStore])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AllDrugStores] CHECK CONSTRAINT [FK_Drug_DrugId]
GO
