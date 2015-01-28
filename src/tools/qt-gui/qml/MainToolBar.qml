import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0

ToolBar {

	RowLayout {
		id:tbLayout

		anchors.fill: parent

		ToolButton {
			id:tbNew
			iconSource: "icons/document-new.png"
			enabled: newKeyAction.enabled
			menu: Menu {
				MenuItem {
					action: newKeyAction
				}
				MenuItem {
					action: newArrayAction
				}
			}
			HelpArea {
				helpText: qsTr("This is the button to create new keys/arrays.")
			}
		}
		ToolButton {
			id:tbDelete
			action: deleteAction
			HelpArea {
				helpText: qsTr("Delete Key")
			}
		}
		ToolButton {
			id:tbImport
			action: importAction
			HelpArea {
				helpText: qsTr("Import from File")
			}
		}
		ToolButton {
			id:tbExport
			action: exportAction
			HelpArea {
				helpText: qsTr("Export to File")
			}
		}
		ToolButton {
			id:tbUndo
			action: undoAction
			HelpArea {
				helpText: qsTr("Undo")
			}
		}
		ToolButton {
			id: tbUndoAll

			implicitWidth: defaultMargins
			enabled: undoAction.enabled
			menu: Menu {
				MenuItem {
					action: undoAllAction
				}
			}
		}
		ToolButton {
			id:tbRedo
			action: redoAction
			HelpArea {
				  helpText: qsTr("Redo")
			}
		}
		ToolButton {
			id: tbRedoAll

			implicitWidth: defaultMargins
			enabled: redoAction.enabled
			menu: Menu {
				MenuItem {
					action: redoAllAction
				}
			}
		}
		ToolButton {
			id:tbSynchronize
			action: synchronizeAction
			HelpArea {
				helpText: qsTr("Synchronize with Key Database")
			}
		}
		Item {
			Layout.fillWidth: true
			height: tbNew.height
		}
		Image {
			id: searchLogo
			source: "icons/edit-find.png"
		}
		SearchField {
			id: searchField

			implicitWidth: keyAreaWidth - searchLogo.implicitWidth - defaultMargins
			focus: true
			onAccepted: {
				if(text !== ""){
					searchResultsListView.model = treeView.treeModel.find(text)
					searchResultsListView.currentIndex = -1
					searchResultsListView.forceActiveFocus()
					searchResultsColorAnimation.running = true
				}
			}
			HelpArea {
				helpText: qsTr("Search Key Database")
			}
		}
	}
}

