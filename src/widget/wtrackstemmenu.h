#pragma once

#include <QKeyEvent>
#include <QMenu>

#include "track/steminfo.h"
#include "util/parented_ptr.h"

class QAction;

class WTrackStemMenu : public QMenu {
    Q_OBJECT
  public:
    WTrackStemMenu(const QString& label,
            QWidget* parent,
            const QString& group,
            const QList<StemInfo>& stemInfo);

  signals:
    void selectedStem(const QString& group, uint stemMask);

  protected:
    virtual void showEvent(QShowEvent* pQEvent) override;
    virtual void keyPressEvent(QKeyEvent* pQEvent) override;
    virtual void keyReleaseEvent(QKeyEvent* pQEvent) override;
    virtual bool eventFilter(QObject* pObj, QEvent* e) override;

  private:
    void updateActions();

    QString m_group;
    bool m_selectMode;
    QList<StemInfo> m_stemInfo;
    uint m_currentSelection;

    std::vector<parented_ptr<QAction>> m_stemActions;
    parented_ptr<QAction> m_selectAction;
};
